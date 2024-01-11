//Busy weight based solution which is not the best solution which uses the counting semaphore

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define BUFFER_SIZE 5

//Array named buffer is created
int buffer[BUFFER_SIZE];
int in=0, out =0;

//Flags to indicate whether a slot is empty or full
int empty_slots=BUFFER_SIZE;
int full_slots=0;

void* producer(void* arg){
	int item=1;
	
	while(1){
		//Wait until there is an empty slot
		while(empty_slots==0);
		
		buffer[in]=item;
		printf("Produced item %d at index %d\n",item,in);
		in=(in+1)%BUFFER_SIZE;
		item++;
		
		//update empty and full slots count
		empty_slots--;
		full_slots++;
		
		sleep(1);
	}
	pthread_exit(NULL);
}

void consumer(void *arg){
	while(1){
		while(full_slots==0);
		
		int item=buffer[out];
		printf("COnsumed item %d from index %d\n",item,out);
		out=(out+1)%BUFFER_SIZE;
		
		//update empty and full slot counts
		empty_slots++;
		full_slots--;
		
		sleep(2);
	}
	pthread_exit(NULL);
}


int main(){
	pthread_t producer_thread, consumer_thread;
	
	//create producer and consumer thread
	pthread_create(&producer_thead, NULL, producer, NULL);
	pthread_create(&consumer_thread, NULL, consumer, NULL);
	
	//Join Threads
	pthread_join(producer_thead, NULL);
	pthread_join(consumer_thread, NULL);
	
	
	return 0;
}


		printf("Consumed item %d from index %d\n",item,out);
		out=(out+1)%BUFFER_SIZE;

		//Update empty and full slot counts
		empty_slots++;
		full_slots--;

		sleep(2);
