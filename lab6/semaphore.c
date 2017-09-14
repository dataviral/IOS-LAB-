#include <stdio.h>
#include <pthread.h>

#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <semaphore.h>

sem_t semP, semvar;
int buff = 0;

void *producer(void *args){

	while(1){
		
		sleep(1);
		// printf("sem: %d\n",sem_getvalue(semC));
		sem_wait(&semvar);
		buff = buff + 1;
		printf("(producer) Buffer Value: %d\n", buff);
		sem_post(&semvar);
		// sem_post(&semP);
		
	}
}


void *consumer(void *args){

		while(1){
		
			// while(buff == 0){
			// 	sem_wait(&semC);
			// }
			sleep(2);
			if(buff == 0){

			}else{
			sem_wait(&semvar);
			buff = buff - 1;
			printf("\t(consumer) Buffer Value: %d\n", buff);
			sem_post(&semvar);
			}
			// if(buff==0){
			// 	printf("Waiting\n");
			// 	sem_wait(&semC);
			// }
			// sem_post(&semC);
			
		}
}


int main(void){

	pthread_t t0, t1;
	int ret;

	ret = sem_init(&semP ,0 ,0);
	if (ret == 1){
		perror("Semaphore(Producer) failed to initialize");
	}
	ret = sem_init(&semvar ,0 ,1);
	if (ret == 1){
		perror("Semaphore(Consumer) failed to initialize");
	}
	pthread_create(&t0, NULL, producer, NULL);
	pthread_create(&t1, NULL, consumer, NULL);

	pthread_join(t0, NULL);
	pthread_join(t1, NULL);

	sem_destroy(&semP);
	sem_destroy(&semvar);

	return 0;
}