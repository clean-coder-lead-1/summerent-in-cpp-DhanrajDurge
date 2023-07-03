#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits - TOO_LOW") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits - TOO_HIGH") {
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers breach type [TOO_HIGH] based on CoolingType - PASSIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
}

TEST_CASE("infers breach type [TOO_HIGH] based on CoolingType - MED_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 45) == TOO_HIGH);
}
TEST_CASE("infers breach type [TOO_HIGH] based on CoolingType - HI_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("infers breach type [TOO_LOW] based on CoolingType - PASSIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("infers breach type [TOO_LOW] based on CoolingType - MED_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -10) == TOO_LOW);
}

TEST_CASE("infers breach type [TOO_LOW] based on CoolingType - HI_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -10) == TOO_LOW);
}

TEST_CASE("infers breach type [NORMAL] based on CoolingType - PASSIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
}

TEST_CASE("infers breach type [NORMAL] based on CoolingType - MED_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35) == NORMAL);
}

TEST_CASE("infers breach type [NORMAL] based on CoolingType - HI_ACTIVE_COOLING") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}

SCENARIO("checkAndAlert", "[checkAndAlert Test Cases]")
{
	GIVEN("Cooling Type is PASSIVE_COOLING and Temperature")
	{
		BatteryCharacter BatteryChar;
		BatteryChar.coolingType = PASSIVE_COOLING;	
		WHEN("coolingType is PASSIVE_COOLING")
		{
			checkAndAlert(TO_CONTROLLER, BatteryChar, 40);
			THEN("BreachType return TOO_HIGH")
			{
				REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
			}
		}
		WHEN("coolingType is PASSIVE_COOLING")
		{
			checkAndAlert(TO_EMAIL, BatteryChar, 40);
			THEN("BreachType return TOO_HIGH")
			{
				REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
			}
		}
	}
}
