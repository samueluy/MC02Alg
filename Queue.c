#include <stdio.h>
#define MAX 256

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
	
void enqueue(char array[MAX], char input, int *tail_index, int *size){
	if(isFull(*size));
	else{
		if (*tail_index >= MAX-1){ // return to index 0 if there is space in the start of the array(circular array)
		*tail_index=0;
		array[*tail_index] = input;
		*size+=1;
		}
		else{ // add a value to the end of the queue
			*tail_index+=1;
			array[*tail_index] = input;
			*size+=1;
		}
	}
}

char dequeue(char array[MAX], int *head_index, int *tail_index, int *size){
	
	if(isEmpty(*size));
	else if(*head_index == MAX-1){ // return to the start of the array if head is at the end of the array
		*head_index=0;
		*size-=1;
		return array[*head_index];
	}
	else{ // remove the value at the tail end
		*size-=1;
		*head_index+=1;
		return array[*head_index];
	}
	array[*head_index] = -1; // close the index value
	
	return 0;
}

void display(char array[MAX], int head_index, int tail_index, int size){
	int i;
	
	if(!isEmpty(size)){
		printf("\nQueue: ");

		if(head_index<=tail_index){
			for(i=head_index; i<=tail_index; i++){
				printf("%c ", array[i]);
			}
		}
		else{ // print circular array
			for(i=head_index; i<=MAX-1; i++)
				printf("%c ", array[i]);
				
			for(i=0;i<=tail_index;i++)
			printf("%c ", array[i]);
		}
		
		printf("\n");
	}
}

int main(void){
	char queue[MAX];
	char input;
	int navigate=0;
	int head_index, tail_index;
	head_index = tail_index = -1; // exit variable	
	int size=0; // size of queue
	
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
				enqueue(queue, input, &tail_index, &size);
				break;
		
		case 2:	printf("Retreived: %c\n", dequeue(queue, &head_index, &tail_index, &size));
				break;
		
		case 3: display(queue, head_index+1, tail_index, size);
				break;
				
		case 4: break;
		}
	}
	
	return 0;
}
