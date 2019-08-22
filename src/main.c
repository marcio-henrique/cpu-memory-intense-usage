#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[]) {

	int pid ; /* identificador de processo */

	pid = fork () ; /* replicacção do processo */

	if ( pid < 0 )
	{ /* se o fork não funcionou */
		perror ("Erro: ") ;
		exit (-1) ; /* encerra o processo com código de erro -1 */ 
	}

	if( pid > 0 ) /* se sou o processo pai*/ 
	{
		char get_cpu[256], get_memory[256], kill[128];

		sprintf(get_memory, "%s%d%s", "pmap ", pid, " | tail -n 1 | awk '{print $2}'");
		sprintf(get_cpu, "%s%d%s", "ps -p ", pid, " -o %cpu | grep -v CPU ");
		sprintf(kill, "%s%d","kill ",pid);

		int i;
		for (i = 0; i < 10; i++)
		{	
			printf("Time: %d second(s)\n", i);
			printf("Memory Usage (Kb):\n");
			system(get_memory);
			printf("CPU Usage(%%):\n");
			system(get_cpu);	//TODO guarde a cada segundo o consumo de memória (em Kilobytes) e CPU (em porcentagem) do processo filho
			printf("\n");

			sleep(1);
		}

		system(kill); //TODO após 10 segundos de execução, mate o proceso filho

	}
	else /* senão, sou o processo filho (pid == 0) */ 
	{
		if (strcmp(argv[1], "cpu") == 0) //TODO se argv[1] for igual a 'cpu', executar código com utilização intensa da UCP
		{
			while(1){}
		}
		else if (strcmp(argv[1], "cpu-mem") == 0) //TODO se argv[1] for igual a 'cpu-mem', executar código com utilização intensa da UCP e da memória
		{
			while(1)
			{
				malloc(0.5);
			}
		}	


	}

	perror ("Erro: ") ; /* execve nãoo funcionou */

	printf ("Tchau !\n") ;
	exit(0) ; /* encerra o processo com sucesso (código 0) */

}