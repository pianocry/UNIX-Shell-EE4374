//
//	EE 4374 Assignment # 2 Command Executer
//	Author: Sergio Galindo
//
#ifndef _SGALINDO_EXEC_
#define _SGALINDO_EXEC_

int executeCmd(char **args);
//ls: lists your files in your current directory (format: $ ls)
void listFiles();
//ls -l: lists your files in long format (format: $ ls -l)
void listFilesLong();
//ls -a: lists all files (format: $ ls -a)
void listFilesAll();
//pwd: displays current working directory (format: $ pwd)
void currentDirectory();
//wc: displays the number of lines, words, and char (format: $wc filename)
void fileCount();
//mkdir: make a new directory (format: $mkdir dirName)
void makeDirectory();
//cat: creates, concatenates and displays text files
void fileConcatenate();

#endif
