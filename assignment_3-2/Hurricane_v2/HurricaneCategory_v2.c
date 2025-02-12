#include <stdio.h>

// Determine Hurricane category based on windspeed and print category
// CAT1: 74-95mph, CAT2: 96-110mph, CAT3: 111-129mph, CAT4: 130-156mph, CAT5: 157+ mph
void getHurricaneCategory() {
  double speedInMph;

  printf("Enter wind speed in MPH: "); // Prompt user for input
  scanf("%lf", &speedInMph); // Set speedInMph to user input

  if(speedInMph >= 157) {
    printf("Category Five Hurricane");
  } else if(speedInMph >= 130) {
    printf("Category Four Hurricane");
  } else if(speedInMph >= 111) {
    printf("Category Three Hurricane");
  } else if(speedInMph >= 96) {
    printf("Category Two Hurricane");
  } else if(speedInMph >= 74) {
    printf("Category One Hurricane");
  } else {
    printf("Not a Hurricane");
  }
}

int main(void) {
  // getHurricaneCategory() will prompt user to input windspeed and print the determined hurricane category
  getHurricaneCategory();

  return 0;
}