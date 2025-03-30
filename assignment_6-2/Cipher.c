#include <stdio.h>
#include <string.h>
#include <ctype.h>

char shiftchar(char character, int shiftamount) {
  if (isupper(character)) {
    // Shift uppercase character by shiftamount, uppercase alphabet starts at 65 in ASCII
    return 65 + (character - 65 - shiftamount + 26) % 26;
  } else if (islower(character)) {
    // Shift lowercase character by shiftamount, lowercase alphabet starts at 97 in ASCII
    return 97 + (character - 97 - shiftamount + 26) % 26;
  } else {
    // Character is not alphabetic, do not change it
    return character;
  }
}

int main(void) {
  // Prompt user for input and store in text var
  printf("Text: ");
  char text[256];
  scanf("%[^\n]", text);

  // Prompt user for the amount they want to shift each character by, store in shiftamount var
  int shiftamount;
  printf("Shift: ");
  scanf("%d", &shiftamount);

  // Split input by spaces
  char* token;
  token = strtok(text, " ");
  
  printf("Cipher: ");

  // Loop over each word
  while(token != 0) {
    // Loop over each char in the word
    for(int i = 0; i < strlen(token); i++) {
      // Find shifted character by passing in current char in token and the shift amount modulo 26 to handle shiftamounts > 26
      char shifted = shiftchar(token[i], shiftamount % 26);

      // Print shifted char
      printf("%c", shifted);
    }

    // Print space between each word
    printf(" ");

    token = strtok(0, " ");
  }

  return 0;
}