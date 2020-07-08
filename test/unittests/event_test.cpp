#include "event.hpp"

#include <catch.hpp>

using namespace centurion::event;

namespace {

[[nodiscard]] auto create_event(Uint32 type) -> Event
{
  SDL_Event sdlEvent;
  sdlEvent.type = type;
  return {sdlEvent};
}

}  // namespace

TEST_CASE("EventType operator==", "[EventType]")
{
  CHECK(EventType::Quit == SDL_EventType::SDL_QUIT);
  CHECK(EventType::AppTerminating == SDL_APP_TERMINATING);
  CHECK(EventType::AppLowMemory == SDL_APP_LOWMEMORY);
  CHECK(EventType::AppWillEnterBackground == SDL_APP_WILLENTERBACKGROUND);
  CHECK(EventType::AppDidEnterBackground == SDL_APP_DIDENTERBACKGROUND);
  CHECK(EventType::AppDidEnterForeground == SDL_APP_DIDENTERFOREGROUND);
  CHECK(EventType::Display == SDL_DISPLAYEVENT);
  CHECK(EventType::Window == SDL_WINDOWEVENT);
  CHECK(EventType::System == SDL_SYSWMEVENT);
  CHECK(EventType::KeyDown == SDL_KEYDOWN);
  CHECK(EventType::KeyUp == SDL_KEYUP);
  CHECK(EventType::TextEditing == SDL_TEXTEDITING);
  CHECK(EventType::TextInput == SDL_TEXTINPUT);
  CHECK(EventType::KeymapChanged == SDL_KEYMAPCHANGED);
  CHECK(EventType::MouseMotion == SDL_MOUSEMOTION);
  CHECK(EventType::MouseButtonDown == SDL_MOUSEBUTTONDOWN);
  CHECK(EventType::MouseButtonUp == SDL_MOUSEBUTTONUP);
  CHECK(EventType::MouseWheel == SDL_MOUSEWHEEL);
  CHECK(EventType::JoystickAxisMotion == SDL_JOYAXISMOTION);
  CHECK(EventType::JoystickBallMotion == SDL_JOYBALLMOTION);
  CHECK(EventType::JoystickHatMotion == SDL_JOYHATMOTION);
  CHECK(EventType::JoystickButtonDown == SDL_JOYBUTTONDOWN);
  CHECK(EventType::JoystickButtonUp == SDL_JOYBUTTONUP);
  CHECK(EventType::JoystickDeviceAdded == SDL_JOYDEVICEADDED);
  CHECK(EventType::JoystickDeviceRemoved == SDL_JOYDEVICEREMOVED);
  CHECK(EventType::ControllerAxisMotion == SDL_CONTROLLERAXISMOTION);
  CHECK(EventType::ControllerButtonDown == SDL_CONTROLLERBUTTONDOWN);
  CHECK(EventType::ControllerButtonUp == SDL_CONTROLLERBUTTONUP);
  CHECK(EventType::ControllerDeviceAdded == SDL_CONTROLLERDEVICEADDED);
  CHECK(EventType::ControllerDeviceRemoved == SDL_CONTROLLERDEVICEREMOVED);
  CHECK(EventType::ControllerDeviceRemapped == SDL_CONTROLLERDEVICEREMAPPED);
  CHECK(EventType::TouchDown == SDL_FINGERDOWN);
  CHECK(EventType::TouchUp == SDL_FINGERUP);
  CHECK(EventType::TouchMotion == SDL_FINGERMOTION);
  CHECK(EventType::DollarGesture == SDL_DOLLARGESTURE);
  CHECK(EventType::DollarRecord == SDL_DOLLARRECORD);
  CHECK(EventType::MultiGesture == SDL_MULTIGESTURE);
  CHECK(EventType::ClipboardUpdate == SDL_CLIPBOARDUPDATE);
  CHECK(EventType::DropFile == SDL_DROPFILE);
  CHECK(EventType::DropText == SDL_DROPTEXT);
  CHECK(EventType::DropBegin == SDL_DROPBEGIN);
  CHECK(EventType::DropComplete == SDL_DROPCOMPLETE);
  CHECK(EventType::AudioDeviceAdded == SDL_AUDIODEVICEADDED);
  CHECK(EventType::AudioDeviceRemoved == SDL_AUDIODEVICEREMOVED);
  CHECK(EventType::SensorUpdate == SDL_SENSORUPDATE);
  CHECK(EventType::RenderTargetsReset == SDL_RENDER_TARGETS_RESET);
  CHECK(EventType::RenderDeviceReset == SDL_RENDER_DEVICE_RESET);
  CHECK(EventType::User == SDL_USEREVENT);

  CHECK(SDL_QUIT == EventType::Quit);
  CHECK(SDL_APP_TERMINATING == EventType::AppTerminating);
  CHECK(SDL_APP_LOWMEMORY == EventType::AppLowMemory);
  CHECK(SDL_APP_WILLENTERBACKGROUND == EventType::AppWillEnterBackground);
  CHECK(SDL_APP_DIDENTERBACKGROUND == EventType::AppDidEnterBackground);
  CHECK(SDL_APP_DIDENTERFOREGROUND == EventType::AppDidEnterForeground);
  CHECK(SDL_DISPLAYEVENT == EventType::Display);
  CHECK(SDL_WINDOWEVENT == EventType::Window);
  CHECK(SDL_SYSWMEVENT == EventType::System);
  CHECK(SDL_KEYDOWN == EventType::KeyDown);
  CHECK(SDL_KEYUP == EventType::KeyUp);
  CHECK(SDL_TEXTEDITING == EventType::TextEditing);
  CHECK(SDL_TEXTINPUT == EventType::TextInput);
  CHECK(SDL_KEYMAPCHANGED == EventType::KeymapChanged);
  CHECK(SDL_MOUSEMOTION == EventType::MouseMotion);
  CHECK(SDL_MOUSEBUTTONDOWN == EventType::MouseButtonDown);
  CHECK(SDL_MOUSEBUTTONUP == EventType::MouseButtonUp);
  CHECK(SDL_MOUSEWHEEL == EventType::MouseWheel);
  CHECK(SDL_JOYAXISMOTION == EventType::JoystickAxisMotion);
  CHECK(SDL_JOYBALLMOTION == EventType::JoystickBallMotion);
  CHECK(SDL_JOYHATMOTION == EventType::JoystickHatMotion);
  CHECK(SDL_JOYBUTTONDOWN == EventType::JoystickButtonDown);
  CHECK(SDL_JOYBUTTONUP == EventType::JoystickButtonUp);
  CHECK(SDL_JOYDEVICEADDED == EventType::JoystickDeviceAdded);
  CHECK(SDL_JOYDEVICEREMOVED == EventType::JoystickDeviceRemoved);
  CHECK(SDL_CONTROLLERAXISMOTION == EventType::ControllerAxisMotion);
  CHECK(SDL_CONTROLLERBUTTONDOWN == EventType::ControllerButtonDown);
  CHECK(SDL_CONTROLLERBUTTONUP == EventType::ControllerButtonUp);
  CHECK(SDL_CONTROLLERDEVICEADDED == EventType::ControllerDeviceAdded);
  CHECK(SDL_CONTROLLERDEVICEREMOVED == EventType::ControllerDeviceRemoved);
  CHECK(SDL_CONTROLLERDEVICEREMAPPED == EventType::ControllerDeviceRemapped);
  CHECK(SDL_FINGERDOWN == EventType::TouchDown);
  CHECK(SDL_FINGERUP == EventType::TouchUp);
  CHECK(SDL_FINGERMOTION == EventType::TouchMotion);
  CHECK(SDL_DOLLARGESTURE == EventType::DollarGesture);
  CHECK(SDL_DOLLARRECORD == EventType::DollarRecord);
  CHECK(SDL_MULTIGESTURE == EventType::MultiGesture);
  CHECK(SDL_CLIPBOARDUPDATE == EventType::ClipboardUpdate);
  CHECK(SDL_DROPFILE == EventType::DropFile);
  CHECK(SDL_DROPTEXT == EventType::DropText);
  CHECK(SDL_DROPBEGIN == EventType::DropBegin);
  CHECK(SDL_DROPCOMPLETE == EventType::DropComplete);
  CHECK(SDL_AUDIODEVICEADDED == EventType::AudioDeviceAdded);
  CHECK(SDL_AUDIODEVICEREMOVED == EventType::AudioDeviceRemoved);
  CHECK(SDL_SENSORUPDATE == EventType::SensorUpdate);
  CHECK(SDL_RENDER_TARGETS_RESET == EventType::RenderTargetsReset);
  CHECK(SDL_RENDER_DEVICE_RESET == EventType::RenderDeviceReset);
  CHECK(SDL_USEREVENT == EventType::User);
}

TEST_CASE("EventType operator!=", "[EventType]")
{
  CHECK(EventType::DollarGesture != SDL_RENDER_DEVICE_RESET);
  CHECK(SDL_MOUSEMOTION != EventType::ControllerDeviceRemoved);
}

TEST_CASE("Event move constructor", "[Event]")
{
  CHECK_NOTHROW(Event{{}});
}

TEST_CASE("Event::refresh", "[Event]")
{
  CHECK_NOTHROW(Event::refresh());
}

TEST_CASE("Event::push", "[Event]")
{
  Event::flush_all();
  {
    SDL_Event sdlEvent{};
    sdlEvent.type = SDL_KEYDOWN;
    Event event{sdlEvent};
    Event::push(event);
  }

  Event event;
  CHECK(event.poll());
  CHECK(event.type() == EventType::KeyDown);
}

TEST_CASE("Event::flush", "[Event]")
{
  Event::refresh();
  Event::flush();

  Event event;
  CHECK(!event.poll());
}

TEST_CASE("Event::flush_all", "[Event]")
{
  Event::flush_all();

  Event event;
  CHECK(!event.poll());
}

TEST_CASE("Event::poll", "[Event]")
{
  SDL_Event sdlEvent{};
  sdlEvent.type = SDL_MOUSEMOTION;
  sdlEvent.motion.x = 839;
  sdlEvent.motion.y = 351;

  Event::flush();
  SDL_PushEvent(&sdlEvent);

  Event event;
  CHECK(event.poll());

  REQUIRE(event.type() == EventType::MouseMotion);
  REQUIRE(event.is<MouseMotionEvent>());

  auto& motionEvent = event.get<MouseMotionEvent>();

  CHECK(motionEvent.x() == sdlEvent.motion.x);
  CHECK(motionEvent.y() == sdlEvent.motion.y);

  Event::flush_all();
}

TEST_CASE("Event::type", "[Event]")
{
  const auto create_sdl_event = [](EventType type) noexcept {
    SDL_Event event{};
    event.type = static_cast<Uint32>(type);
    return event;
  };

  const auto type = EventType::TouchMotion;
  auto sdlEvent = create_sdl_event(type);

  Event::flush_all();
  SDL_PushEvent(&sdlEvent);

  Event event;
  CHECK(event.poll());
  CHECK(event.type() == type);

  Event::flush_all();
}

TEST_CASE("Event::empty", "[Event]")
{
  SECTION("Empty")
  {
    Event event;
    CHECK(event.empty());
  }

  SECTION("Not empty")
  {
    const auto event = create_event(SDL_AUDIODEVICEADDED);
    CHECK(!event.empty());
  }
}

TEST_CASE("Event::is", "[Event]")
{
  SECTION("AudioDeviceEvent")
  {
    const auto added = create_event(SDL_AUDIODEVICEADDED);
    const auto removed = create_event(SDL_AUDIODEVICEREMOVED);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(added.is<AudioDeviceEvent>());
    CHECK(removed.is<AudioDeviceEvent>());
    CHECK(!wrong.is<AudioDeviceEvent>());
  }

  SECTION("ControllerAxisEvent")
  {
    const auto event = create_event(SDL_CONTROLLERAXISMOTION);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(event.is<ControllerAxisEvent>());
    CHECK(!wrong.is<ControllerAxisEvent>());
  }

  SECTION("ControllerButtonEvent")
  {
    const auto up = create_event(SDL_CONTROLLERBUTTONUP);
    const auto down = create_event(SDL_CONTROLLERBUTTONDOWN);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(up.is<ControllerButtonEvent>());
    CHECK(down.is<ControllerButtonEvent>());
    CHECK(!wrong.is<ControllerButtonEvent>());
  }

  SECTION("ControllerDeviceEvent")
  {
    const auto added = create_event(SDL_CONTROLLERDEVICEADDED);
    const auto removed = create_event(SDL_CONTROLLERDEVICEREMOVED);
    const auto remapped = create_event(SDL_CONTROLLERDEVICEREMAPPED);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(added.is<ControllerDeviceEvent>());
    CHECK(removed.is<ControllerDeviceEvent>());
    CHECK(remapped.is<ControllerDeviceEvent>());
    CHECK(!wrong.is<ControllerDeviceEvent>());
  }

  SECTION("DollarGestureEvent")
  {
    const auto gesture = create_event(SDL_DOLLARGESTURE);
    const auto record = create_event(SDL_DOLLARRECORD);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(gesture.is<DollarGestureEvent>());
    CHECK(record.is<DollarGestureEvent>());
    CHECK(!wrong.is<DollarGestureEvent>());
  }

  SECTION("DropEvent")
  {
    const auto begin = create_event(SDL_DROPBEGIN);
    const auto complete = create_event(SDL_DROPCOMPLETE);
    const auto file = create_event(SDL_DROPFILE);
    const auto text = create_event(SDL_DROPTEXT);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(begin.is<DropEvent>());
    CHECK(complete.is<DropEvent>());
    CHECK(file.is<DropEvent>());
    CHECK(text.is<DropEvent>());
    CHECK(!wrong.is<DropEvent>());
  }

  SECTION("JoyAxisEvent")
  {
    const auto motion = create_event(SDL_JOYAXISMOTION);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(motion.is<JoyAxisEvent>());
    CHECK(!wrong.is<JoyAxisEvent>());
  }

  SECTION("JoyBallEvent")
  {
    const auto motion = create_event(SDL_JOYBALLMOTION);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(motion.is<JoyBallEvent>());
    CHECK(!wrong.is<JoyBallEvent>());
  }

  SECTION("JoyButtonEvent")
  {
    const auto up = create_event(SDL_JOYBUTTONUP);
    const auto down = create_event(SDL_JOYBUTTONDOWN);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(up.is<JoyButtonEvent>());
    CHECK(down.is<JoyButtonEvent>());
    CHECK(!wrong.is<JoyButtonEvent>());
  }

  SECTION("JoyDeviceEvent")
  {
    const auto added = create_event(SDL_JOYDEVICEADDED);
    const auto removed = create_event(SDL_JOYDEVICEREMOVED);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(added.is<JoyDeviceEvent>());
    CHECK(removed.is<JoyDeviceEvent>());
    CHECK(!wrong.is<JoyDeviceEvent>());
  }

  SECTION("JoyHatEvent")
  {
    const auto motion = create_event(SDL_JOYHATMOTION);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(motion.is<JoyHatEvent>());
    CHECK(!wrong.is<JoyHatEvent>());
  }

  SECTION("KeyboardEvent")
  {
    const auto up = create_event(SDL_KEYUP);
    const auto down = create_event(SDL_KEYDOWN);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(up.is<KeyboardEvent>());
    CHECK(down.is<KeyboardEvent>());
    CHECK(!wrong.is<KeyboardEvent>());
  }

  SECTION("MouseButtonEvent")
  {
    const auto up = create_event(SDL_MOUSEBUTTONUP);
    const auto down = create_event(SDL_MOUSEBUTTONDOWN);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(up.is<MouseButtonEvent>());
    CHECK(down.is<MouseButtonEvent>());
    CHECK(!wrong.is<MouseButtonEvent>());
  }

  SECTION("MouseMotionEvent")
  {
    const auto motion = create_event(SDL_MOUSEMOTION);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(motion.is<MouseMotionEvent>());
    CHECK(!wrong.is<MouseButtonEvent>());
  }

  SECTION("MouseWheelEvent")
  {
    const auto wheel = create_event(SDL_MOUSEWHEEL);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(wheel.is<MouseWheelEvent>());
    CHECK(!wrong.is<MouseWheelEvent>());
  }

  SECTION("MultiGestureEvent")
  {
    const auto gesture = create_event(SDL_MULTIGESTURE);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(gesture.is<MultiGestureEvent>());
    CHECK(!wrong.is<MultiGestureEvent>());
  }

  SECTION("QuitEvent")
  {
    const auto quit = create_event(SDL_QUIT);
    const auto wrong = create_event(SDL_KEYUP);

    CHECK(quit.is<QuitEvent>());
    CHECK(!wrong.is<QuitEvent>());
  }

  SECTION("TextEditingEvent")
  {
    const auto editing = create_event(SDL_TEXTEDITING);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(editing.is<TextEditingEvent>());
    CHECK(!wrong.is<TextEditingEvent>());
  }

  SECTION("TextInputEvent")
  {
    const auto input = create_event(SDL_TEXTINPUT);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(input.is<TextInputEvent>());
    CHECK(!wrong.is<TextInputEvent>());
  }

  SECTION("TouchFingerEvent")
  {
    const auto motion = create_event(SDL_FINGERMOTION);
    const auto up = create_event(SDL_FINGERUP);
    const auto down = create_event(SDL_FINGERDOWN);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(motion.is<TouchFingerEvent>());
    CHECK(up.is<TouchFingerEvent>());
    CHECK(down.is<TouchFingerEvent>());
    CHECK(!wrong.is<TouchFingerEvent>());
  }

  SECTION("WindowEvent")
  {
    const auto window = create_event(SDL_WINDOWEVENT);
    const auto wrong = create_event(SDL_QUIT);

    CHECK(window.is<WindowEvent>());
    CHECK(!wrong.is<WindowEvent>());
  }
}

TEST_CASE("Event::get", "[Event]")
{
  SECTION("Const")
  {
    const auto quit = create_event(SDL_QUIT);

    CHECK_NOTHROW(quit.get<QuitEvent>());
    CHECK_THROWS(quit.get<WindowEvent>());
  }

  SECTION("Non-const")
  {
    auto quit = create_event(SDL_QUIT);

    CHECK_NOTHROW(quit.get<QuitEvent>());
    CHECK_THROWS(quit.get<WindowEvent>());
  }
}

TEST_CASE("Event::try_get", "[Event]")
{
  SECTION("Const")
  {
    const auto event = create_event(SDL_MOUSEMOTION);

    CHECK(event.try_get<MouseMotionEvent>());
    CHECK(!event.try_get<WindowEvent>());
  }

  SECTION("Non-const")
  {
    auto event = create_event(SDL_MULTIGESTURE);

    CHECK(event.try_get<MultiGestureEvent>());
    CHECK(!event.try_get<JoyHatEvent>());
  }
}
