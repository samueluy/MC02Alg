#include <stdio.h>
#define MAX 256

struct queue{
	char strContent[MAX];
	int head_index;
	int tail_index;
	int size;
};

int isEmpty(int size){ // Check if the queue is empty
	if(size==0){
		printf("\nQueue is empty\n");
		return 1;
	}
	else
		return 0;
}

int isFull(int size){ // Check if the queue is full
	if(size == MAX){
		printf("Queue is full\n");
		return 1;
	}
	else
		return 0;
}
	
void enqueue(struct queue* Q, char input){
	if(isFull(Q->size));
	else{
		if (Q->tail_index >= MAX-1){ // return to index 0 if there is space in the start of the array(circular array)
		Q->tail_index=0;
		Q->strContent[Q->tail_index] = input;
		Q->size+=1;
		}
		else{ // add a value to the end of the queue
			Q->tail_index+=1;
			Q->strContent[Q->tail_index] = input;
			Q->size+=1;
		}
	}
}

char dequeue(struct queue* Q){
	
	if(isEmpty(Q->size));
	else if(Q->head_index == MAX-1){ // return to the start of the array if head is at the end of the array
		Q->head_index=0;
		Q->size-=1;
		return Q->strContent[Q->head_index];
	}
	else{ // remove the value at the tail end
		Q->size-=1;
		Q->head_index+=1;
		return Q->strContent[Q->head_index];
	}
	Q->strContent[Q->head_index] = -1; // close the index value
	
	return 0;
}

void display(struct queue Q){
	int i;
	
	if(!isEmpty(Q.size)){
		printf("\nQueue: ");

		if(Q.head_index<=Q.tail_index){
			for(i=Q.head_index; i<=Q.tail_index; i++){
				printf("%c ", Q.strContent[i]);
			}
		}
		else{ // print circular array
			for(i=Q.head_index; i<=MAX-1; i++)
				printf("%c ", Q.strContent[i]);
				
			for(i=0;i<=Q.tail_index;i++)
			printf("%c ", Q.strContent[i]);
		}
		
		printf("\n");
	}
}

int main(void){
	struct queue queue;
	char input;
	int navigate=0;
	
	queue.head_index = queue.tail_index = -1; // exit variable	
	queue.size=0;
	
	while(navigate!= 4){
		printf("\n[1] Enqueue\n");
		printf("[2] Dequeue\n");
		printf("[3] Display\n");
		printf("[4] Exit\n");
		printf("Enter: ");
		scanf("%d", &navigate);
		
		switch(navigate){
		case 1: printf("Input: ");
				scanf(" %c", &input);
				enqueue(&queue, input);
				break;
		
		case 2:	printf("Retreived: %c\n", dequeue(&queue));
				break;
		
		case 3: display(queue);
				break;
				
		case 4: break;
		}
	}
	
	return 0;
}

