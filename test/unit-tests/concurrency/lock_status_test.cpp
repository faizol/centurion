#include <gtest/gtest.h>

#include <iostream>  // clog

#include "common.hpp"
#include "concurrency.hpp"

TEST(LockStatus, Values)
{
  ASSERT_EQ(0, cen::to_underlying(cen::LockStatus::Success));
  ASSERT_EQ(SDL_MUTEX_TIMEDOUT, cen::to_underlying(cen::LockStatus::TimedOut));
  ASSERT_EQ(-1, cen::to_underlying(cen::LockStatus::Error));
}

TEST(LockStatus, ToString)
{
  ASSERT_THROW(cen::ToString(static_cast<cen::LockStatus>(2)), cen::exception);

  ASSERT_EQ("Success", cen::ToString(cen::LockStatus::Success));
  ASSERT_EQ("TimedOut", cen::ToString(cen::LockStatus::TimedOut));
  ASSERT_EQ("Error", cen::ToString(cen::LockStatus::Error));

  std::clog << "Lock status example: " << cen::LockStatus::TimedOut << '\n';
}
