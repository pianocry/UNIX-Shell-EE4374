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


int executeCmd(char **args)
{
  
   
  execvp(args[0],args);

}


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

