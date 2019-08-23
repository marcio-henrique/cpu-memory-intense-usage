#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void father(int pid)
{
	char get_cpu[256], get_memory[256], kill[128];

	sprintf(get_memory, "%s%d%s", "pmap ", pid, " | tail -n 1 | awk '{print $2}'");		//command to show the memory usage in Kb from a process on linux terminal
	sprintf(get_cpu, "%s%d%s", "ps -p ", pid, " -o %cpu | grep -v CPU ");			//command to show the UCP usage in % from a process on linux terminal
	sprintf(kill, "%s%d","kill ",pid);							//string command to kill process on linux

	int i;
	for (i = 0; i < 10; i++)
	{	
		printf("Time: %d second(s)\n", i);
		printf("Memory Usage (Kb):\n");
		system(get_memory);					//execute a string command on linux terminal
		printf("CPU Usage(%%):\n");
		system(get_cpu);
		printf("\n");

		sleep(1);	//delay 1 second
	}

	system(kill);
}

void child (char arg[])
{
	if (strcmp(arg, "ucp") == 0) 	//intense UCP utilization
	{
		while(1){}
	}
	else if (strcmp(arg, "ucp-mem") == 0) 		//intense UCP and principal memory utilization
	{
		char *memory = (char *) malloc(sizeof(char));	//memory allocation to char (1 byte)
		int i;
		for(i = 0; 1; i++)
		{
			if (i % 10 == 0 && memory != NULL)		//restrict memory allocation on loop and check if memory allocation is available
			{
				memory = (char *) malloc(sizeof(char));
			}
		}
	}
}

int main (int argc, char *argv[], char *envp[]) {

	int pid ; 		// process id

	pid = fork () ; // new process created by duplicating the current process

	if ( pid < 0 )	// if fork failed
	{ 
		perror ("Error: ") ;		//error status print
		exit (-1) ; 			// finish the process with a -1 error code
	}
	else if( pid > 0 ) 		// else, if i am father process
	{
		father(pid);
	}
	else 	// else, if i am child process (pid == 0)
	{
		child(argv[1]);
	}

	perror ("Error: ") ; 	// status print

	printf ("Bye!\n") ;
	exit(0) ; 				// finish the process successfully (0 code)

}
