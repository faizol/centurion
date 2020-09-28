#include "thread.hpp"

#include <cassert>

#include "detail/to_string.hpp"
#include "detail/utils.hpp"
#include "exception.hpp"

namespace cen {

thread::thread(task_type task, nn_czstring name, void* data)
    : m_thread{SDL_CreateThread(task, name, data)}
{
  if (!m_thread) {
    throw sdl_error{"Failed to create thread"};
  }
}

thread::~thread() noexcept
{
  if (joinable()) {
    join();
  }
}

void thread::detach() noexcept
{
  if (m_joined || m_detached) {
    return;
  }

  SDL_DetachThread(m_thread);

  m_detached = true;
  assert(m_detached != m_joined);
}

auto thread::join() noexcept -> int
{
  if (m_joined || m_detached) {
    return 0;
  }

  int status{};
  SDL_WaitThread(m_thread, &status);

  m_joined = true;
  assert(m_detached != m_joined);

  return status;
}

auto thread::joinable() const noexcept -> bool
{
  return !m_joined && !m_detached;
}

auto thread::was_joined() const noexcept -> bool
{
  return m_joined;
}

auto thread::was_detached() const noexcept -> bool
{
  return m_detached;
}

auto thread::get_id() const noexcept -> id
{
  return SDL_GetThreadID(m_thread);
}

auto thread::name() const -> std::string
{
  return SDL_GetThreadName(m_thread);
}

auto thread::get() noexcept -> SDL_Thread*
{
  return m_thread;
}

auto thread::get() const noexcept -> const SDL_Thread*
{
  return m_thread;
}

void thread::sleep(milliseconds<u32> ms) noexcept
{
  SDL_Delay(ms.count());
}

auto thread::set_priority(thread_priority priority) noexcept -> bool
{
  return SDL_SetThreadPriority(static_cast<SDL_ThreadPriority>(priority)) == 0;
}

auto thread::current_id() noexcept -> id
{
  return SDL_ThreadID();
}

auto to_string(const thread& thread) -> std::string
{
  using detail::to_string;
  return "[thread | ptr: " + detail::address_of(thread.get()) +
         ", name: " + thread.name() +
         ", id: " + to_string(thread.get_id()).value() + "]";
}

auto operator<<(std::ostream& stream, const thread& thread) -> std::ostream&
{
  stream << to_string(thread);
  return stream;
}

}  // namespace cen
