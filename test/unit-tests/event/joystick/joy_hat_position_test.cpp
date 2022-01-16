#include <gtest/gtest.h>

#include <iostream>  // clog

#include "common.hpp"
#include "event.hpp"

using Position = cen::JoyHatPosition;

TEST(JoyHatPosition, Values)
{
  ASSERT_EQ(to_underlying(Position::LeftUp), SDL_HAT_LEFTUP);
  ASSERT_EQ(to_underlying(Position::Left), SDL_HAT_LEFT);
  ASSERT_EQ(to_underlying(Position::LeftDown), SDL_HAT_LEFTDOWN);
  ASSERT_EQ(to_underlying(Position::Up), SDL_HAT_UP);
  ASSERT_EQ(to_underlying(Position::Centered), SDL_HAT_CENTERED);
  ASSERT_EQ(to_underlying(Position::Down), SDL_HAT_DOWN);
  ASSERT_EQ(to_underlying(Position::RightUp), SDL_HAT_RIGHTUP);
  ASSERT_EQ(to_underlying(Position::Right), SDL_HAT_RIGHT);
  ASSERT_EQ(to_underlying(Position::RightDown), SDL_HAT_RIGHTDOWN);
}

TEST(JoyHatPosition, ToString)
{
  ASSERT_THROW(ToString(static_cast<Position>(SDL_HAT_RIGHTDOWN + 1)), cen::exception);

  ASSERT_EQ("LeftUp", ToString(Position::LeftUp));
  ASSERT_EQ("Left", ToString(Position::Left));
  ASSERT_EQ("LeftDown", ToString(Position::LeftDown));
  ASSERT_EQ("Up", ToString(Position::Up));
  ASSERT_EQ("Centered", ToString(Position::Centered));
  ASSERT_EQ("Down", ToString(Position::Down));
  ASSERT_EQ("RightUp", ToString(Position::RightUp));
  ASSERT_EQ("Right", ToString(Position::Right));
  ASSERT_EQ("RightDown", ToString(Position::RightDown));

  std::clog << "Joystick hat position example: " << Position::Left << '\n';
}
