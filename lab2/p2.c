#include "headers.h"


int main(void){

	printf("Execution Started\n<Parent Process>\n");

	int arr[5] = {1,2,3,4,5};

	int i;
	int sum, product;

	printf("The array is --> ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	int cid = fork();

	if (cid == 0){
		// CHILD Process
		printf("\n<Child Process>current id=%d parent id=%d\n", getpid(),getppid());
		sum = 0;
		for(i=0; i<5; i++){
			sum += arr[i];
		}
		printf("Sum of the array's elements is: %d\n", sum);
		printf("\nChild Process Terminated\n");
	}
	else{
		// Parent Process
		printf("\n<Parent Process Resumed>current id=%d parent id=%d\n", getpid(),getppid());
		product = 1;
		for(i=0; i<5; i++){
			product *= arr[i];
		}
		printf("Product of the array's elements is: %d\n", product);
		printf("\nParent Process Terminated\n");
	}

	return 0;
}