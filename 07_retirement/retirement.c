#include<stdio.h>
#include<stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired){

  int currentAge = startAge;
  if (currentAge == 327){
    for(int i = 0; i < (working.months); i++){
      printf("Age %3d month %2d you have $%.2lf\n", currentAge/12, currentAge % 12, initial);
      initial += initial * working.rate_of_return;
      initial += working.contribution;
      currentAge += 1;
    }
  }
  
  if (currentAge == (working.months + startAge)){
   printf("retired.omnths %d", retired.months);
   for(int j = 0; j < retired.months; j++){
     printf("Age %3d month %2d you have $%.2lf\n", currentAge/12, currentAge%12, initial);
     initial += initial *retired.rate_of_return;
     initial += retired.contribution;
     currentAge += 1;
  }
 }
}

int main(){
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  int startAge = 327;
  double initial = 21345;
  retirement(startAge, initial, working, retired);
  
  return EXIT_SUCCESS;
}
