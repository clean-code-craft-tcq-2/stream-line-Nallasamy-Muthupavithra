#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Receiver.h"
#include "catch.hpp"

TEST_CASE("Tests to check if data is correctly read from file")
{
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  BMSReceiver(Temperature,SOC,ChargeRate);
  
  float expectedoutput[3][3] = {{00,00,00}, {00,00,00},{00,00,00}};
  for(int i=0;i<3;i++)
  {
    REQUIRE(Temperature[i] == expectedoutput[i][0]);
    REQUIRE(SOC[i] == expectedoutput[i][1]);
    REQUIRE(ChargeRate[i] == expectedoutput[i][2]);
  }
}
