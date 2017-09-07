#include "headers.h"

int main(void){

	printf("Execution Started id: %d pid: %d\n\n", getpid(), getppid());
	fork();
	fork();
	fork();
	printf("Hello World id:%d pid: %d\n", getpid(), getppid());	 
}