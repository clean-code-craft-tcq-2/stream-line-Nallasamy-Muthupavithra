#include "Receiver.h"

void GetSensorDataFromConsole(float* Current, float* Temperature)
{
  FILE* fp = fopen("./BMS_DataParameter.txt","r");
  float Curr_readings, Temp_readings;
  
  for(int i=0; fscanf(fp,"%f \t %f \n", &Curr_readings,&Temp_readings)!=EOF; i++)
    {
      *(Current+i) = Curr_readings;
      *(Temperature+i) = Temp_readings;
    }
  fclose(fp);
}

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

void PrintReceivedDataOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA)
{
  int readingIndex = 0;
  printf("Data received from sender\n");
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    printf("%f\n",BMSParameter[readingIndex]);
  }
  printf("Max value: %f, Min value: %f, SMA: %f\n",MaxValue,Minvalue,SMA);
  
}

void BMSReceiver(float* Current, float* Temperature)
{
  GetSensorDataFromConsole(Current, Temperature);
  PrintReceivedDataOnConsole(Current,GetMaxReadingValue(Current),GetMinReadingValue(Current),GetSMAValue(Current));
  PrintReceivedDataOnConsole(Temperature,GetMaxReadingValue(Temperature),GetMinReadingValue(Temperature),GetSMAValue(Temperature));  
}
