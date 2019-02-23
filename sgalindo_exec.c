//	EE 4374 Assignment # 2 Command Executer
//	Author: ???
//
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
//#include <direct.h>
//#include <dir.h>
//#include <string.h>
#include <sys/stat.h>

#include "sgalindo_argtok.h"
#include "sgalindo_exec.h"


int execBackground(char **args)
{
    int i;
    // check for the ampersand at the end of the set of tokens
    i = 0;
    while(args[i] != 0)
    {
         i++;
    }                       // traverse to the end of the tokens
    if(args[i-1][0] == '&') // check the last token
    {
        free(args[i-1]);
        args[i-1] = NULL;  // remove the ampersand
        return 1;
    }
    else
    {
        return 0;
    }
}

//ls: lists your files in your current directory (format: $ ls)
void listFiles(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return;
}
//ls -l: lists your files in long format (format: $ ls -l)
void listFilesLong(){return;}


//ls -a: lists all files (format: $ ls -a)
void listFilesAll(){
    struct dirent *dir;  // Pointer for directory entry 
    // opendir() returns a pointer of DIR type.  
    DIR *d = opendir("."); 
    if (d == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return; 
    } 
    while ((dir = readdir(d)) != NULL) 
            printf("%s\n", dir->d_name); 

    closedir(d);     
    return; 
} 


//pwd: displays current working directory (format: $ pwd)
void currentDirectory(){
     char dir[100]; 
    // printing current working directory 
    printf("%s\n", getcwd(dir, 100)); 
    return;
}


//wc: displays the number of lines, words, and char (format: $wc filename)
void fileCount(char* args){
 FILE *fp;
 char *filename;
 filename = args[1];
 char ch;
 // Initialize counter variables
 int linecount = 0;
 int wordcount = 0;
 int charcount = 0;
 // Prompt user to enter filename
  printf("Filename :");
  //gets(filename);
    // Open file in read-only mode
   fp = fopen(filename,"r");
   // If file opened successfully, then write the string to file
   if ( fp )
   {
    //Repeat until End Of File character is reached.    
       while ((ch=getc(fp)) != EOF) {
          // Increment character count if NOT new line or space
            if (ch != ' ' && ch != '\n') { ++charcount; }
          // Increment word count if new line or space character
           if (ch == ' ' || ch == '\n') { ++wordcount; }     
          // Increment line count if new line character
           if (ch == '\n') { ++linecount; }
       }
       if (charcount > 0) {
        ++linecount;
        ++wordcount;
       }
    }
   else
      {
         printf("Failed to open the file\n");
        }
    printf("Lines : %d \n", linecount);
    printf("Words : %d \n", wordcount);
    printf("Characters : %d \n", charcount);
getchar();
return;
}

//mkdir: make a new directory (format: $mkdir dirName)
void makeDirectory(char **dirname){
    int check;  
  //  clrscr(); 
  
    check = mkdir(dirname[1]); 
  
    // check if directory is created or not 
    if (!check){
        printf("Directory created\n"); 
    }
    else { 
        printf("Unable to create directory\n"); 
        exit(1); 
    } 
  
    //getch(); 
  
    system("dir/p"); 
    //getch(); 
    return;
}

//cat: creates, concatenates and displays text files
void fileConcatenate(){
  
   int c = 0;
   while (p[c] != '\0') {
      c++;      
   }
   int d = 0;
 
   while (q[d] != '\0') {
      p[c] = q[d];
      d++;
      c++;    
   }
   p[c] = '\0';
    

    return;
}


int executeCmd(char **args)
{
    (char*)args = args;

    printf("IN EXECUTE %s \n",args[0]);
    if( args == "ls" ){
        listFiles();
        printf("IN LIST FILES\n" );
        return 0;
    }
    else{
        printf("FAILED\n" );
        return -1;
    }
    
}



