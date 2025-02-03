#include <stdio.h>
#include <string.h>

int main(void) {
  char tweet[142]; // Declare tweet var with size of 141 chars + 1 for null terminator
    
  printf("Enter your Tweet: "); // Prompt user for input
  fgets(tweet, 142, stdin); // Store user input in tweet var

  // Check tweet string length, if >140 print Rejected, else print Posted
  if (strlen(tweet) > 140) { 
    printf("Rejected\n");
  } else {
    printf("Posted\n");
  }

  return 0;
}