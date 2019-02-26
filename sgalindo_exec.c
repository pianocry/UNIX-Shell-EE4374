//	EE 4374 Assignment # 2 Command Executer
//	Author: ???
//
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
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

int executeCmd(char **args)
{
   char** arg = args;
  pid_t myPid;
  if(execBackground(arg)==1){
    myPid = fork();
    if(myPid < 0){
      fprintf(stderr,"ERROR\n");
      return -1;
    }
    else if(myPid ==0){
      printf("CHILD");
      execvp(arg[0],arg);
    }  
    return 0;
  }
  /*  
else{
    pid_t myPidBack; 
    myPidBack = fork();
    if(myPidBack < 0){
      fprintf(stderr,"ERROR\n");
      return -1;
    }
    else if(myPidBack ==0){
      execvp(arg[0],arg);
    }
    else{
      waitpid(myPidBack,NULL,0);
    }  
    return 0;
  }
  */
}


