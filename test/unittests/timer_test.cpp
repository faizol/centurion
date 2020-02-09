#include "catch.hpp"
#include "timer.h"
#include <cmath>
#include <cstdint>
#include <SDL.h>

using namespace centurion;

TEST_CASE("Timer::sleep", "[Timer]") {
  CHECK_NOTHROW(Timer::sleep(10));
//  const auto millis = 100;
//
//  const int before = Timer::millis();
//  Timer::sleep(millis);
//  const int after = Timer::millis();
//
//  const int diff = after - before;
//  CHECK(std::abs(millis - diff) < 10); // allow slight difference
}

TEST_CASE("Timer::high_res", "[Timer]") {
  CHECK_NOTHROW(Timer::high_res());
//  const int64_t time = Timer::high_res();
//  const int64_t sdlTime = SDL_GetPerformanceCounter();
//  const int64_t diff = std::abs(time - sdlTime);
//  CHECK(diff < 25);
}

TEST_CASE("Timer::high_res_freq", "[Timer]") {
  CHECK(Timer::high_res_freq() == SDL_GetPerformanceFrequency());
}