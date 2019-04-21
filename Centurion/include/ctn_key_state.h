#pragma once
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
#include <memory>
#include <vector>

namespace centurion {
namespace input {

class KeyState;
typedef std::shared_ptr<KeyState> KeyState_sptr;
typedef std::unique_ptr<KeyState> KeyState_uptr;
typedef std::weak_ptr<KeyState> KeyState_wptr;

/**
\brief The KeyState class provides information about the keyboard state.
\since 1.1.0
*/
class KeyState final {
 private:
  int nKeys;
  const Uint8* stateArr;
  std::vector<Uint8> prevStates;

  void CopyStates() noexcept;

 public:
  KeyState();

  ~KeyState();

  /**
  \brief Refreshes the information about the key state. This method does NOT
  call SDL_PumpEvents().
  \since 1.1.0
  */
  void Update() noexcept;

  /**
  \brief Returns true if the key associated with the supplied SDL_Scancode is
  being pressed.
  \param code - the SDL_Scancode that corresponds to the desired key to check.
  \since 1.1.0
  */
  bool IsPressed(const SDL_Scancode code) const;

  /**
  \brief Returns true if the key associated with the supplied SDL_Scancode has
  been continously held down.
  \param code - the SDL_Scancode that corresponds to the desired key to check.
  \since 1.1.0
  */
  bool IsHeldDown(const SDL_Scancode code) const;

  /**
  \brief Returns true if the key associated with the supplied SDL_Scancode was
  released.
  \param code - the SDL_Scancode that corresponds to the desired key to check.
  \since 1.1.0
  */
  bool WasReleased(const SDL_Scancode code) const;

  /**
  \brief Returns true if the key associated with the supplied SDL_Scancode is
  triggered for the first time, since it was pressed. Returns false otherwise.
  \param code - the SDL_Scancode that corresponds to the desired key to check.
  \since 1.1.0
  */
  bool IsFirstTrigger(const SDL_Scancode code) const;

  /**
  \brief Returns the number of possible keys.
  \since 1.1.0
  */
  inline int GetNumberOfKeys() const noexcept { return nKeys; }

  /**
  \brief Returns a shared pointer that points to a KeyState.
  \since 1.1.0
  */
  static KeyState_sptr CreateShared();

  /**
  \brief Returns a unique pointer that points to a KeyState.
  \since 1.1.0
  */
  static KeyState_uptr CreateUnique();

  /**
  \brief Returns a weak pointer that points to a KeyState.
  \since 1.1.0
  */
  static KeyState_wptr CreateWeak();
};

}  // namespace input
}  // namespace centurion