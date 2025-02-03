#include <stdio.h>

int main(void) {
  int inputNum;
  int sum = 0;

  printf("Enter a number to see if it is Perfect: "); // Prompt user input
  scanf("%d", &inputNum); // Set inputNum to user input

  // Loop through all numbers between 1 and inputNum to see if they are divisible, if so increase sum by that number
  for(int i = 1; i < inputNum; i++) {
    if(inputNum % i == 0) {
      sum += i;
    }
  }

  // If sum and inputNum match, it is a perfect number
  if(sum == inputNum) {
    printf("Perfect Number");
  } else {
    printf("Not A Perfect Number");
  }

  return 0;
}