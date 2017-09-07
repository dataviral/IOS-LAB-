#include "headers.h"

int main(int argc, char *argv[]){

	int c1 = fork();

	if(c1==0){
		int c2 = fork();
		if(c2==0){
			int num1 = atoi(argv[1]);
			int num2 = atoi(argv[2]);
			exit((num2+num1));
		}else{
			int status;
			wait(&status);
			int ret = WEXITSTATUS(status);
			exit(ret*2);
		}
	}
	else{
		int status;
		wait(&status);
		int ret = WEXITSTATUS(status);
		printf("%d\n", ret);
	}

	return 0;
}