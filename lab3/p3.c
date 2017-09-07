#include "p3.h"
 
int main(int argc, char *argv[]){

	printf("----------Parent Starting Execution------------\n");
	printf("< pid :%d>\n", getpid());
	printf("< child spawned>\n");
	int cid = fork();
	
	if(cid == 0){
		printf("\n----------Child Starting Execution------------\n");
		printf("<pid :%d>\n", getpid());

		// sleep(5);
		// int ccid = fork();
		// if (ccid==0){
		// 	execl("/bin/ps", "ps", "T", 0);
		// }
		// else{
		// 	wait(&ccid);
		printf("\n----------Child Exited------------\n");
			exit(0);
	
		// }
			}
	else{
		printf("\n----------Parent Sleeping------------\n");
		sleep(5);
		execl("/bin/ps", "ps", "T", 0);
		printf("\n\n\n");
		printf("\n----------Parent Wokeup------------\n");
		printf("\n----------Parent Exited------------\n");
	}

	return 0;
}