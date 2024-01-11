#include <unistd.h>
int main()
{
	//writes Hello on screen
	write(1, "Hello\n", 6);
	
	//writes He on screen
	write(1, "Hello", 2);
	
	//writes garbages on screen
	write(1, "\nHello", 20);
	
	return 0;
}	
