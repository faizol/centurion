#pragma once

#include <SDL.h>
#undef main  // don't use the SDL main function
#include "gtest/gtest.h"

#include <centurion_everything.h>
#include <stdio.h>
#include <stdexcept>
#include <string>

// Global namespace usage declarations, because I'm lazy
using namespace centurion;
using namespace centurion::geo;
using namespace centurion::visuals;
using namespace centurion::audio;
using namespace centurion::input;
using namespace centurion::tools;
using namespace centurion::events;

// Useful exception aliases
using inv_arg = std::invalid_argument;
using except = std::exception;