#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getTokened(char* original, char token)
{
  char* returnString = malloc(strlen(original) * sizeof(char));
  int i=0;
  while(original[i] != token)
  {
    returnString[i] = original[i];
    i++;
  }
  returnString[i] = '\0';
  return returnString;
}

char* getRemaining(char* original, char* split)
{
  char* string = malloc(strlen(original) * sizeof(char));
  int length = strlen(split) +1;
  int i=0;
  for(;length < strlen(original); length++)
  {
    string[i] = original[length];
    i++;
  }
  return string;
}
