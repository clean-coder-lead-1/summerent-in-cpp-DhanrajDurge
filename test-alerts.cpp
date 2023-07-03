#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits - TOO_LOW") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits - TOO_HIGH") {
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits - NORMAL") {
  REQUIRE(inferBreach(-5, 20, 30) == NORMAL);
}
