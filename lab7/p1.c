#include <stdio.h>
#include <unistd.h>

void printArray(int m, int n, int **arr){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ", arr[m][n]);
		} 
		printf("\n");
	}
}

int main(void){

	int m=5, n=3;
	int i,j;
	int alloc[m][n], max[m][n], need[m][n];


	// Allocation Matrix

	printf("Allocation Matrix\n");
	for(i=0; i<m; i++){
		for(j=0; j<n-1; j++){
			scanf("%d ", &alloc[i][j]);
		}
			scanf("%d\n", &alloc[i][n-1]);
	}

	for(i=0; i<m; i++){
	for(j=0; j<n; j++){
		printf("%d ", alloc[i][j]);
	} 
	printf("\n");
	}

	// MAX Matrix

	printf("MAX Matrix\n");
	for(i=0; i<m; i++){
		for(j=0; j<n-1; j++){
			scanf("%d ", &max[i][j]);
		}
			scanf("%d\n", &max[i][n-1]);
	}

	for(i=0; i<m; i++){
	for(j=0; j<n; j++){
		printf("%d ", max[i][j]);
	} 
	printf("\n");
	}

	// NEED

	printf("NEEDS Matrix\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		} 
	}

 
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d ", need[i][j]);
		}	 
		printf("\n");
	}

	// Bankers

	int work[n], finish[m], safeSeq[m];
	printf("Enter Available of the three resources\n");
	getchar();
	getchar();
	// for(i=0;i<n;i++)
	// 	scanf("%d\n",&work[i]);
	work[0] = 1;
	work[1] = 10;
	work[2] = 10;
	for(i=0;i<m;i++)
		finish[i] = 0;

	int found;
	int count=0;

	while(count < m){
		found = 0;
		for(i=0; i<m; i++){
			if(finish[i] == 0){
				for(j=0; j <n; j++)
					if(need[i][j] > work[j])
						break;

				if(j==n){
					int k;
					for(k=0; k<n; k++)
						work[k] += alloc[i][k];
					safeSeq[count++] = i;
					finish[i] = 1;
					found = 1;
				}
			}
		}
		if(found == 0){
			printf("System is not in safe state\n");
			for(i=0; i <m; i++)
				printf("%d ", finish[i]);
			return 1;
		}
	}

	printf("System is in safe state\n");
	for(i=0; i <m; i++)
		printf("%d ", safeSeq[i]);

	return 0;
}