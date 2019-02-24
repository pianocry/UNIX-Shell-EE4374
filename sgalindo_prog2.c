//
//	EE 4374 Assignment # 2 Shell (Test Function)
//	Author: ???
//
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "sgalindo_argtok.h"
#include "sgalindo_exec.h"

int main()
{
    int i;
	int inputSize;
	char buff[128];		// Character buffer
	char **args;

    write(1, "Welcome to the Student Shell (type 'x' to exit)\n", 48);
	while(1)
	{
		// Request a line of input
		write(1, "\nshell -> ", 10);

		// Read the line
		inputSize = read(0, buff, 128);

		// Strip off carriage return
		buff[inputSize-1] = '\0';

		if(buff[0] == '\0')
			continue;

		if((buff[0] == 'x') && (buff[1] == '\0'))
		{
			exit(0);
		}

		// make the argument vector
		args = argtok(buff);

		//print tokens
		//print_tokens(args);
	       
		// execute the command
		executeCmd(args);
		printf("%d\n",execBackground(args) );

	}

	return 0;

}
