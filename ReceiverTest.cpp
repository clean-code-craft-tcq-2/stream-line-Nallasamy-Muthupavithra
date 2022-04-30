#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Receiver.h"
#include "catch.hpp"

TEST_CASE("Test to check Receiver statistics") 
{ 
   BatteryChargingParameters ExpectedData[NO_OF_READINGS], Max, Min, SMA;
   BMSReceiver(BatteryChargingParameters.Current, BatteryChargingParameters.Temperature);
   float Current_loc, Temperature_loc;
    
   FILE * file= fopen("./BMS_DataFromConsole.txt","r");                                                                  
   for(int i = 0 ; i < NO_OF_READINGS; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0;fscanf(file, "%f,%f\n", &Current_loc,&Temperature_loc)!=EOF ;i++)
        {
            ExpectedData[i].Current = Current_loc;
            ExpectedData[i].Temperature = Temperature_loc;
        }
     }
       
     REQUIRE( (BatteryChargingParameters.Current[i] - ExpectedData[i].Current) <= 0.001);
     REQUIRE( (BatteryChargingParameters.Current[i] - ExpectedData[i].Temperature) <= 0.001);
   }
   fclose(file);
 
    Min.Current=  GetMaxReadingValue(Current);
    Max.Current = GetMinReadingValue(Current);
    SMA.Current = GetSMAValue(Current);
    Min.Temperature=  GetMaxReadingValue(Temperature);
    Max.Temperature = GetMinReadingValue(Temperature);
    SMA.Temperature = GetSMAValue(Temperature);
   
    REQUIRE( abs(Min.Current - (-13.774300) ) <=0.001);
    REQUIRE( abs(Max.Current - 14.962000 ) <=0.001);
    REQUIRE( abs(SMA.Current - 1.511800 ) <=0.001);
    REQUIRE( abs(Min.Temperature - 0.216200 ) <=0.001);
    REQUIRE( abs(Max.Temperature - 43.833599 ) <=0.001);
    REQUIRE( abs(SMA.Temperature - 23.042278 ) <=0.001);
}
