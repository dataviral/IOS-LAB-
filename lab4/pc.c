#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

pthread_t tid[2];

struct Buffer{
    char buff;
    int len;
    int size;
}typedef Buffer;


Buffer buff;
int modifying = 0;

void* doSomeThing(void *arg)
{
    
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {	
        printf("\n Produces processing\n");

        while(1){
                while(buff.len<buff.size){
                    buff.len++;
                    printf("Buffer (Producer) :%d\n", buff.len);
                }
        }   
    }
    else
    {
        printf("\n Consumer processing\n");
    	while(1){

               while(buff.len!=0){
                    printf("Buffer (Consumer) :%d\n", buff.len);
                    buff.len--;
                }

        }
    }

    return NULL;
}


int main(void){
	short int i = 0;
    int err;

    buff.len = 0;
    buff.size = 20;
    buff.buff = 0;
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