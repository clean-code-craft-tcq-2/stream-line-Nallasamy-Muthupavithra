#include "Receiver.h"

  float Current[50] = {};
  float Temperature[50] = {};
void GetSensorDataFromConsole()
{
   char ReadString[1000] = {};
   for(int i=0;i<NO_OF_READINGS ; i++)
   {
   char *token;
   scanf("%s", ReadString);
   token = strtok (ReadString, ",");
   //printf( "%s\n", token );
   Current[i] = atof(token);
   printf ("Current[%d]: %.4f\n",i,Current[i]);
   token = strtok (NULL, ",");
   //printf( "%s\n", token );
   Temperature[i]= atof(token);
   printf("Temperature[%d]: %.4f\n", i,Temperature[i]);
   }
}

/*float GetMaxReadingValue(float *BMSParameter)
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
  
}*/

int main()
{
  GetSensorDataFromConsole();
  //PrintReceivedDataOnConsole(Current,GetMaxReadingValue(Current),GetMinReadingValue(Current),GetSMAValue(Current));
  //PrintReceivedDataOnConsole(Temperature,GetMaxReadingValue(Temperature),GetMinReadingValue(Temperature),GetSMAValue(Temperature)); 
  return 0;
}
