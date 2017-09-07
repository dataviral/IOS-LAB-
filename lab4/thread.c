#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

pthread_t tid[2];
long long int i = 0;

void* doSomeThing(void *arg)
{
    
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {	
        printf("\n First thread processing\n");
        while(1){
        	// printf("\r          ");
        	printf("%Ld\n", i);
        	i++;
        }
    }
    else
    {
        printf("\n Second thread processing\n");
    	while(1){
    		// printf("\r          ");
        	printf("%Ld\n", i);
        	i--;
        }
        
    }

    return NULL;
}


int main(void){
	short int i = 0;
    int err;
    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread (%d) created successfully\n", i+1);

        i++;
    }

    sleep(10);
    return 0;
}