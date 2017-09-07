#include "p1.h"
 
int main(int argc, char *argv[]){

	printf("----------Parent Starting Execution------------\n");
	printf("< pid :%d>\n", getpid());
	printf("< child spawned>\n");
	int cid = fork();
	
	if(cid == 0){
		printf("\n----------Child Starting Execution------------\n");
		printf("<pid :%d>\n", getpid());

		char command[100];
		strcpy(command, "/bin/");
		strcat(command, argv[1]);
		printf("Execting command, '%s' in child process\n\n", argv[1]);

		execl(command, argv[1], 0);
		printf("\n");
	}
	else{
		printf("\n----------Parent Resuming Execution------------\n");
		wait(&cid);
	}

	return 0;
}