#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "centurion.h"

using namespace centurion;

int main(int argc, char** argv) {
  Centurion c;
  return Catch::Session().run(argc, argv);
}