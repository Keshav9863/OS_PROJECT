#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#define buffersize 10
pthread_mutex_t mutex;
pthread_t p1[20],p2[20];
sem_t full,empty;
int counter;
int buffer[buffersize];
void done()
{
	pthread_mutex_init(&mutex,NULL);
	sem_init(&full,1,0);
	sem_init(&empty,1,buffersize);
	counter=0;
}

void write1(int item)
{
	buffer[counter++]=item;
}

int read1()
{
	return(buffer[--counter]);
}

void *producer(void *param)
{
	int waittime,item,i;
	item=rand()%10;
	waittime=rand()%10;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	printf("\n Producer has produced item:%d\n",item);
	write1(item);
	pthread_mutex_unlock(&mutex);
	sem_post(&full);	
}
void *consumer(void *param)
{
	int waittime,item;
	item=rand()%10;
	waittime=rand()%10;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	item=read1();
	printf("\n Consumer has consumed item:%d\n",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);

}





int main()
{
	int a,b,i;
	done();
	printf("Enter the number of producers:");
	scanf("%d",&a);
	printf("Enter the number of consumers:");
	scanf("%d",&b);
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
			pthread_join(p2[i],NULL);
		}
		exit(0);

}
