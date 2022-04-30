#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Receiver.h"
#include "catch.hpp"

GetSensorDataFromConsole(Current, Temperature);

/*TEST_CASE("Tests to check if data is correctly read from file")
{
  float Current[NO_OF_READINGS] = {0};
  float Temperature[NO_OF_READINGS] = {0};
  GetSensorDataFromConsole(Current, Temperature);
  
  float expectedoutput[2][2] = {{00,00}, {00,00}};
  for(int i=0;i<2;i++)
  {
    REQUIRE(Current[i] == expectedoutput[i][0]);
    REQUIRE(Temperature[i] == expectedoutput[i][1]);
  }
} */
