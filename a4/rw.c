//READER WRITER PROBLEM
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

void *writer_thr(int temp);// function prototypes
void *reader_thr(int temp);
sem_t mutex;// declare semaphore variable
sem_t wrt;
int readcount=0;//readcount is integer variable that keeps track of how many processes are currently reading the object.
int nwt,nrd;// nwt-->no of writer&nrd-->no of reader

void main()
{
    long int i;
    sem_init(&mutex,0,1);// initialise semaphore variables
    sem_init(&wrt,0,1);
    pthread_t reader[100],writer[100];
    //taking input
    printf("\nEnter number of readers:");
    scanf("%d",&nrd);
    printf("\nEnter number of writers:");
    scanf("%d",&nwt);
    //creating threads
    for(i=1;i<=nwt;i++)
    {
        pthread_create(&writer[i],NULL,(void *)writer_thr,(int *)i);
 
    }
    for(i=1;i<=nrd;i++)
    {
        pthread_create(&reader[i],NULL,(void *)reader_thr,(int *)i);
    }
    //joining thread
    for(i=1;i<=nrd;i++)
    {
        pthread_join(reader[i],NULL);
    }
    for(i=1;i<nwt;i++)
    {
        pthread_join(writer[i],NULL);
    }

    sem_destroy(&wrt);//destroying a semaphore that has been initialised by sem_init.
    sem_destroy(&mutex);
}

void *reader_thr(int temp)
{
    printf("\nReader %d is trying to enter database for reading.",temp);
    sem_wait(&mutex);
    readcount++;// The number of readers has now increased by 1.
    if(readcount==1)
    sem_wait(&wrt);//this ensure that no writer can enter if there is one reader.sem_wait same like wait operation .
    sem_post(&mutex);//other readers can enter while this current reader in its critical section.
    printf("\nReader %d is now reading in database.",temp);
    sem_wait(&mutex);
    readcount--;//a reader wants to leave from the critical section.
    if(readcount==0)//no reader is left in the critical section.
    sem_post(&wrt); //writers can enter now
    sem_post(&mutex);//readers leaves.
    printf("\nReader %d has left the database.\n",temp); 
    sleep(3);//process suspend execution for a specified period
}

void *writer_thr(int temp)
{
    printf("\nWriter %d is trying to enter database for modifying data",temp);
    sem_wait(&wrt);//writer request for critical section for entry
    printf("\nWriter %d is writing in database.",temp);
    sleep(3);
    printf("\nWriter %d is leaving the database.\n",temp);
    sem_post(&wrt);//leave the critical section .sem_post same as signal .
}