#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* producer(void *arg)
{
	long unsigned i;
	
	
	while(1){
		while(counter < 5){
			counter += 1;
			pthread_mutex_lock(&lock);
			printf("\n (Prodcuer) Buffer Value :%d", counter);
			for(i=0; i<(0x10011111);i++);
			// printf("\n Producer has finished:\nBuffer Value :%d", counter);
			pthread_mutex_unlock(&lock);
			for(i=0; i<(0x10011111);i++);
		}
	}
	

	return NULL;
}

void* consumer(void *arg)
{
	
	unsigned long i;
	
	while(1){

		while(counter != 0){

		pthread_mutex_lock(&lock);
		counter -= 1;
		printf("\n \t\t(Consumer) Buffer Value :%d", counter);
		for(i=0; i<(0x10011111);i++);
		// printf("\n Consumer has finished:\nBuffer Value :%d", counter);
		pthread_mutex_unlock(&lock);
	for(i=0; i<(0x10011111);i++);
		}
	}
	

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init has failed\n");
		return 1;

	}
	error = pthread_create(&(tid[0]), NULL, &producer,NULL);


	error =pthread_create(&(tid[1]), NULL, &consumer,NULL);

	if(error != 0){
		printf("\nThread can't be created :[%s]",strerror(error));
	}
	while(1);
	pthread_mutex_destroy(&lock);
	return 0;
}