#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void initialize()
{
	
	
}

void *producer(void *producer)
{
	
	
}

void *consumer(void *consumer)
{
	
	
}


int main()
{
	pthread_t p1[10],p2[10];
	int a,b,i;
	intialize();
	printf("\t\t\tEnter the number of consumers:\t\t");
	scanf("%d",a);
	printf("\n\t\t\tEnter the number of producers:\t\t");
	scanf("%d",b);
	for(i=0;i<a;i++)
		{
			pthread_create(&p1[i],NULL,producer,NULL);
		}
	for(i=0;i<b;i++)
		{
			pthread_create(&p2[i],NULL,consumer,NULL);
		}
	for(i=0;i<a;i++)
		{
			pthread_join(p1[i],NULL);
		}
	for(i=0;i<b;i++)
		{
			pthread_create(p2[i],NULL);
		}
}
