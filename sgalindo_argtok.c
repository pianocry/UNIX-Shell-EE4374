//
//	EE 4374 Assignment # 1 Argument Tokenizer
//	Author: Sergio Galindo

#include <stdio.h>
#include <stdlib.h>
#include "sgalindo_argtok.h"

/* Tokenizes the string argument into an array of tokens. */
char ** argtok(char * input)
{
  char** tokens = NULL;
  int length = 0;
  int start = find_word_start(input,0);
  int end = find_word_end(input,start);
  int words = count_words(input);
  tokens = (char **)malloc(words * sizeof(char *)+1);

  for(int i = 0; i < words; i++)
    {
      *(tokens + i) = (char*)malloc(length * sizeof(char)+1);
      length = end - start;
      for(int j = 0; j <= length; j++)
	{
	  *(*(tokens+i)+j) = *(input + start);
	  start++;
	}
      start = find_word_start(input,(end+1));
      end = find_word_end(input,start);
    }
  tokens[words] = NULL;
  return tokens;
}

/* Free all tokens and the array containing the tokens. */
void free_tokens(char** input)
{
  int i = 0;
  while(input[i] != NULL)
    {
      free(input[i]);
      i++;
    }
  free(input);
}

/* Print all tokens. */
void print_tokens(char** input)
{
  int i = 0;
  while(input[i] != NULL)
    {
      printf("%s\n", input[i]);
      i++;
    }
}

/* Count the number of words in the string argument. */
int count_words(char *input)
{
  int inWord = 1;
  int outOfWord = 0;
  int state = outOfWord;
  int wordCount = 0;
  int strLength = string_length(input);

  for(int i = 0; i <= strLength; i++)
    if(input[i] == ' ' || input[i] == '\0' || input[i] == '\t')
      state = outOfWord;
    else if(state == outOfWord)
      {
	state = inWord;
	wordCount++;
      }
  return wordCount;
}

/* Find the end index for the next word.
   char* str - the string to search.
   int pos - the index to start searching. */
int find_word_end(char *input, int index)
{
  int inWord = 1;
  int outOfWord = 0;
  int state = outOfWord;
  int endIndex = 0;
  int wordCount = 0;
  int strLength = string_length(input);

  for(int i = index; i <= strLength; i++)
    if(input[i] == ' ' || input[i] == '\0' || input[i] == '\t')
      {
	if(wordCount == 1)
	  {
	    state = outOfWord;
	    endIndex = i-1;
	    i = strLength;
	  }
	else
	  state = outOfWord;
      }
    else if(state == outOfWord)
      {
	state = inWord;
	wordCount++;
      }
  return endIndex;
}

/* Find the starting index for the next word.
   char* str - the string to search.
   int pos - the index to start searching. */
int find_word_start(char *input, int index)
{
  int inWord = 1;
  int outOfWord = 0;
  int state = outOfWord;
  int startIndex = 0;
  int strLength = string_length(input);

  for(int i = index; i <= strLength; i++)
    if(input[i] == '\0')
      {
	startIndex = 1;
	i = strLength;
      }
    else if(input[i] == ' ' || input[i] == '\t')
      state = outOfWord;
    else if(state == outOfWord)
      {
	startIndex = i;
	i = strLength;
      }
  return startIndex;
}

/* Evaluate if the character c is an acceptable character for
   a token (e.g. '0' is acceptable but '\t' is not.
   Returns 0 if not, 1 if yes. */
char is_valid_character(char c)
{
  if(c == '\t' || c == '\n' || c == '\v')
    return 0;
  else
    return 1;
}

/* Count the number of characters in the string argument. */
int string_length(char *input)
{
  char *input2 = input;

  while(*input)
    {
      input++;
    }
  return input - input2;
}
