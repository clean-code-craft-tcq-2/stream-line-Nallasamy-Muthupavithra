#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Receiver.h"
#include "catch.hpp"

TEST_CASE("Test to check Receiver statistics") 
{ 
   float Current_loc, Temperature_loc;
   float Current[NO_OF_READINGS] = {0};
   float Temperature[NO_OF_READINGS] = {0};
   float ExpectedCurrent[NO_OF_READINGS] = {0};
   float ExpectedTemperature[NO_OF_READINGS] = {0};
   
   BMSReceiver(Current, Temperature);
    
   FILE * file= fopen("./BMS_DataFromConsole.txt","r");                                                                  
   for(int i = 0 ; i < NO_OF_READINGS; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0;fscanf(file, "%f,%f\n", &Current_loc,&Temperature_loc)!=EOF ;i++)
        {
            ExpectedCurrent[i] = Current_loc;
            ExpectedTemperature[i] = Temperature_loc;
        }
     }
       
     REQUIRE( (Current[i] - ExpectedCurrent[i]) <= 0.001);
     REQUIRE( (Temperature[i] - ExpectedTemperature[i]) <= 0.001);
   }
   fclose(file);
 
    float MinCurrent =  GetMaxReadingValue(Current);
    float MaxCurrent = GetMinReadingValue(Current);
    float SMACurrent = GetSMAValue(Current);
    float MinTemperature=  GetMaxReadingValue(Temperature);
    float MaxTemperature = GetMinReadingValue(Temperature);
    float SMATemperature = GetSMAValue(Temperature);
   
    REQUIRE( abs(MinCurrent - (-13.774300) ) <=0.001);
    REQUIRE( abs(MaxCurrent - 14.962000 ) <=0.001);
    REQUIRE( abs(SMACurrent - 1.511800 ) <=0.001);
    REQUIRE( abs(MinTemperature - 0.216200 ) <=0.001);
    REQUIRE( abs(MaxTemperature - 43.833599 ) <=0.001);
    REQUIRE( abs(SMATemperature - 23.042278 ) <=0.001);
}
