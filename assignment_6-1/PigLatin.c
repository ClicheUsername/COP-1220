#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isvowel(char character) {
  // Lowercase the character for ease of checking, if it equals a e i o or u we know it is a vowel
  char lower = tolower(character);
  if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
    return 1;
  } else {
    return 0;
  }
}

int main(void) {
  printf("Enter the text you'd like to translate to Pig Latin: \n");

  char input[250];

  // Store user's text input in input var
  scanf("%[^\n]", input);

  char* token;

  // Split input by spaces
  token = strtok(input, " ");

  while(token != 0) {
    char punct = '\0';
    // Check if last character in token is punctuation, if yes then set punct to that punctuation and remove it from token
    if(ispunct(token[strlen(token)-1])) {
      punct = token[strlen(token) - 1];
      token[strlen(token) - 1] = '\0';
    }

    // Count the number of consonants at the start of token so we know how many to move to the end
    int cluster = 0;
    while (token[cluster] && !isvowel(token[cluster])) {
        cluster++;
    }

    // If the first character of token is a vowel, just add yay to the token
    if(isvowel(token[0])) {
      printf("%syay ", token);
    } else {
      // Move all consonants from the beginnning of the token to the end and add ay
      printf("%s%cay ", token + cluster, tolower(token[0]));
    }

    // If there was punctuation at the end of the original token, print it
    if(punct != '\0') {
      printf("%c ", punct);
    }

    token = strtok(0, " ");
  }

  return 0;
}