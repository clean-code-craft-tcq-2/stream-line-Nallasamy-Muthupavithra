#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_READINGS 50

void GetSensorDataFromConsole(float *Current, float *Temperature);
float GetMaxReadingValue(float *BMSParameter);
float GetMinReadingValue(float *BMSParameter);
float GetSMAValue(float *BMSParameter);
void PrintStatisticsOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA);
void BMSReceiver(float *Current, float *Temperature);
