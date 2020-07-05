#include "joy_button_event.h"

#include <catch.hpp>

using namespace centurion;
using namespace centurion::event;

TEST_CASE("JoyButtonEvent move constructors", "[JoyButtonEvent]")
{
  CHECK_NOTHROW(JoyButtonEvent{{}});
}

TEST_CASE("JoyButtonEvent::set_which", "[JoyButtonEvent]")
{
  JoyButtonEvent event;

  const auto which = 92;
  event.set_which(which);

  CHECK(event.which() == which);
}

TEST_CASE("JoyButtonEvent::set_button", "[JoyButtonEvent]")
{
  JoyButtonEvent event;

  const auto button = 44;
  event.set_button(button);

  CHECK(event.button() == button);
}

TEST_CASE("JoyButtonEvent::set_state", "[JoyButtonEvent]")
{
  JoyButtonEvent event;

  const auto state = ButtonState::Pressed;
  event.set_state(state);

  CHECK(event.state() == state);
}

TEST_CASE("JoyButtonEvent::which", "[JoyButtonEvent]")
{
  SDL_JoyButtonEvent sdlEvent;
  sdlEvent.which = 27;
  JoyButtonEvent event{sdlEvent};

  CHECK(event.which() == sdlEvent.which);
}

TEST_CASE("JoyButtonEvent::button", "[JoyButtonEvent]")
{
  SDL_JoyButtonEvent sdlEvent;
  sdlEvent.button = 99;
  JoyButtonEvent event{sdlEvent};

  CHECK(event.button() == sdlEvent.button);
}

TEST_CASE("JoyButtonEvent::state", "[JoyButtonEvent]")
{
  SDL_JoyButtonEvent sdlEvent;
  sdlEvent.state = SDL_RELEASED;
  JoyButtonEvent event{sdlEvent};

  CHECK(event.state() == ButtonState::Released);
}