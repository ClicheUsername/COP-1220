#include <stdio.h>

int main() {
  int minTemp = -30;
  int maxTemp = 130;
  int temperatures[5];
  int sum = 0;

  for (int i = 0; i < 5; i++) {
    do {
      printf("Enter temperature %d: ", i + 1);
      scanf("%d", &temperatures[i]);

      if (temperatures[i] < minTemp || temperatures[i] > maxTemp) {
        printf("Temperature %d is invalid. Please enter a temperature between "
               "-30 and 130.\n",
               temperatures[i]);
      }
    } while (temperatures[i] < minTemp || temperatures[i] > maxTemp);

    sum += temperatures[i];
  }

  int hotter = 1, colder = 1;
  for (int i = 1; i < 5; i++) {
    if (temperatures[i] <= temperatures[i - 1]) {
      hotter = 0;
    }
    if (temperatures[i] >= temperatures[i - 1]) {
      colder = 0;
    }
  }

  if (hotter) {
    printf("Getting warmer\n");
  } else if (colder) {
    printf("Getting cooler\n");
  } else {
    printf("It's a mixed bag\n");
  }

  printf("5-day Temperatures: [");
  for (int i = 0; i < 5; i++) {
    if (i == 4) {
      printf("%d]\n", temperatures[i]);
    } else {
      printf("%d, ", temperatures[i]);
    }
  }

  printf("Average temperature is %.1f degrees", (double)sum / 5);

  return 0;
}
