//	EE 4374 Assignment # 2 Command Executer
//	Author: Sergio Galindo
//
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "sgalindo_argtok.h"
#include "sgalindo_exec.h"
static int counter; 
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
      printf("EXEC BACKGROUND : \n");
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

  if(execBackground(args)==1){
  counter++;
    printf("PASSED BACKGROUND FUNCTION \n");
    pid_t  myPid;
    myPid = fork();
    
     
    if(myPid < 0){
      fprintf(stderr,"ERROR\n");
      return -1;
    }
    else if(myPid ==0){
      //      counter++;
      printf("[%d]  %ld \n",counter,getpid());    

      printf("CHILD\n");
      execvp(args[0],args);
      if(counter > 1)
	kill(myPid,9);
    }  
    return 0;
  }
  else{ 
    
    counter = 0;
    pid_t myPidBack;
    myPidBack = fork();
    if(myPidBack < 0){
      fprintf(stderr,"ERROR\n");
      return -1;
    }
    else if(myPidBack ==0){
      execvp(args[0],args);
    }
    else{
      waitpid(myPidBack,NULL,0);
    }  
    return 0;
  }
}


