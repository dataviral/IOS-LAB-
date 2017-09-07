#include "headers.h"

int main(int argc, char *argv[]){

	int n = atoi(argv[1]);

	int cid = fork();

	if(cid==0){
		int x=1,y=1;
		int i;
		int s = 0;
		printf("0 1 1 ");
		for(i=0; i<n; i++){
			s = x+y;
			printf("%d ", s);	
			x = y;
			y = s;
		}
	}
	else{

	}

	return 0;
}