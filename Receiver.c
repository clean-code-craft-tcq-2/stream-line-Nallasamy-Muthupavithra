#include "Receiver.h"

/* Read sensors data from console */
void GetSensorDataFromConsole(float* Current, float* Temperature)
{
  FILE* fp = fopen("./BMS_DataFromConsole.txt","r");
  float Curr_readings, Temp_readings;
  
  for(int i=0; fscanf(fp, "%f,%f \n", &Curr_readings,&Temp_readings)!=EOF; i++)
    {
      *(Current + i) = Curr_readings;
      *(Temperature + i) = Temp_readings;
    }
  fclose(fp);
}

/* Calculate Max value from sensor readings */
float GetMaxReadingValue(float *BMSParameter)
{
  int readingIndex;
  float MaxReadingValue = BMSParameter[0];
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    if(BMSParameter[readingIndex] > MaxReadingValue)
    {
      MaxReadingValue = BMSParameter[readingIndex];
    }
  }
  
  return MaxReadingValue;
}

/* Calculate Min value from sensor readings */
float GetMinReadingValue(float *BMSParameter)
{
  int readingIndex;
  float MinReadingValue = BMSParameter[0];
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    if(BMSParameter[readingIndex] < MinReadingValue)
    {
      MinReadingValue = BMSParameter[readingIndex];
    }
  }
  
  return MinReadingValue;
}

/* Calculate Simple Moving Average of last 5 readings from sensor */
float GetSMAValue(float *BMSParameter)
{
  float SMAValue = 0.0;
  float Sum = 0.0;
  int readingIndex = 0;
  for(readingIndex = (NO_OF_READINGS-5); readingIndex < NO_OF_READINGS; readingIndex++)
  {
    Sum += BMSParameter[readingIndex];
  }
  
  SMAValue = Sum/5;
  
  return SMAValue;  
}

/* Print separated sensor readings, Max, Min and SMA on the console */ 
void PrintStatisticsOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA)
{
  int readingIndex = 0;
  printf("Data received from sender\n");
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    printf("%f\n",BMSParameter[readingIndex]);
  }
  printf("Max value: %f, Min value: %f, SMA: %f\n",MaxValue,Minvalue,SMA);  
}

/* BMSReceiver main function */
void BMSReceiver(float *Current, float *Temperature)
{
  GetSensorDataFromConsole(Current,Temperature);
  PrintStatisticsOnConsole(Current,GetMaxReadingValue(Current),GetMinReadingValue(Current),GetSMAValue(Current));
  PrintStatisticsOnConsole(Temperature,GetMaxReadingValue(Temperature),GetMinReadingValue(Temperature),GetSMAValue(Temperature)); 
}
