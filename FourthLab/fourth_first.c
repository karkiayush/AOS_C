#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// global variable
int g = 5;

int main()
{
	int pid;

	// creating child and parent process
	pid = fork();

	// Executed by parent process
	if (pid > 0)
	{
		int x = g;
		x++;
		sleep(1);
		g = x;
		printf("\n parent g=%d", g);
	}

	// Executed by child process
	else
	{
		int y = g;
		y--;
		sleep(1);
		g = y;
		printf("\n Child g=%d", g);
	}

	// Executed by both parent & child process
	printf("\n last g=%d", g);
	return 0;
}
