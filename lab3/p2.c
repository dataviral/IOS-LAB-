#include "p2.h"
 
int main(int argc, char *argv[]){

	printf("----------Parent Starting Execution------------\n");
	printf("< pid :%d>\n", getpid());
	printf("< child spawned>\n");
	int cid = fork();
	
	if(cid == 0){
		printf("\n----------Child Starting Execution------------\n");
		printf("<pid :%d>\n", getpid());

		sleep(5);
		int ccid = fork();
		if (ccid==0){
			execl("/bin/ps", "ps", "-af", 0);
		}
		else{
			wait(&ccid);
			printf("Child Exited\n");	
		}
			}
	else{
		printf("\n----------Parent Resuming Execution------------\n");
		printf("\n----------Parent Exited------------\n");
	
	}

	return 0;
}