//
//	EE 4374 Assignment # 1 Argument Tokenizer
//	Author: Sergio Galindo
//

#ifndef _SGALINDO_ARGTOK_
#define _SGALINDO_ARGTOK_

/* Counts number of characters in the string argument.*/
int string_length(char*);

/* Checks if the character c is an acceptable character for
   a token Returns 0 if not, 1 if yes. */
char is_valid_character(char c);

/* Find the starting index for the next word. */
int find_word_start(char*, int i);

/* Find the end index for the next word. */
int find_word_end(char*, int i);

/* Count the number of words in the string argument. */
int count_words(char*);

/* Print all tokens. */
void print_tokens(char**);

/* Free all tokens and the array containing the tokens. */
void free_tokens(char**);

/* Tokenizes the string argument into an array of tokens.*/
char** argtok(char*);

#endif
