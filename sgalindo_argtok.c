//
//	EE 4374 Assignment # 1 Argument Tokenizer
//	Author: Sergio Galindo
//
#include <stdio.h>
#include <stdlib.h>
#include "sgalindo_argtok.h"
#include "sgalindo_exec.h"

int string_length(char* str){
	//gives the length of entire string
	int length = 0;
	while(*str != '\0' ){
		length++;
		str++;
	}
	return length;
}

char is_valid_character(char c){
	//checks if character given is within the valid range set  
	if( c == 32 || c == 9 ){
		return 0;
	}
	else{
		return 1;
	}
}

int find_word_start(char* c, int i){
  //finds the start index of a string
	int index = i;
	while(!(is_valid_character( *(c+index)) )){
		index++;
	}
	return index;
}

int find_word_end(char* str, int start_pos){
  //finds ending index of the string
	int index = start_pos;
	while(is_valid_character( *(str+index) )){
		index++;
	}
	return index;
}

int count_words(char* word){
  //returns the number of individual tokens in the string
	int count = 0;
	int start = 0;
	int end = 0;
	int length = string_length(word);
	char** ptr;
	
	while(1){
		start = find_word_start(word,end);
		ptr = &word;
		if( start >= length ){
			break;
		}
		count++;
		end = find_word_end(word,start);
	}
	return count;
}
// char** argtok(char* token){
//   //tokenizes a string and returns them in array of memory allocated tokens
// 	int length = string_length(token);
// 	int words = count_words(token);
// 	char* ptoken = token;
// 	char** tokens = malloc(words*sizeof(char*));
	
// 	printf("The String Tokenized:  \n");
//         // index less then words
// 	for(int index = 0;index < words; index++){
// 	  //pointer - token 
// 		int start = find_word_start(token,ptoken-token);
// 		int end = find_word_end(token,start);
// 		int token_size = end - start;
		
// 		ptoken = token + start;
// 		*(tokens+index) = malloc(length*sizeof(char));
		
// 		for(int jindex = 0;jindex< token_size; jindex++){
// 			*(*(tokens+index)+jindex) = *ptoken;
// 			ptoken++;
// 		}
		
// 	}
// 	tokens[words] = NULL;
// 	return tokens;
// }


char** argtok(char* words){

char ** token = NULL;
    int start = find_word_start(words,0);
    int end = find_word_end(words,start);
    int w_count = count_words(words);
    int temp = end - start;

    token = ((char ** ) malloc(sizeof(char*) * w_count + 1)); //rows
    for(int i = 0; i < w_count ; i++){
        *(token + i) = (char*) malloc(sizeof(char) * temp+1); //coloms
        temp = end - start;
        for(int j = 0;  j <= temp+1; j++){ //
            *(*(token+i)+j) = *(words + (start)); //copying

            start++;

        }

        start = find_word_start(words, end+1);
        end = find_word_end(words,start); 
    }
    token[count_words(words)+1] = '\0';
    return token;
}

void print_tokens(char** token){
  //prints the tokens
	int index = 0;
	while(token[index]){
		printf("%s\n",token[index]);
		index++;
	}
}

void free_tokens(char** token){
  //frees the memory allocated for the tokens
	int index = 0;
	while(token[index] != NULL){
		free(token[index]);
	}
	free(token);
}

