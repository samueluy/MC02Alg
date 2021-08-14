#include <stdio.h>
#define MAX 256

// still need to make it a circular array

int isEmpty(char array[MAX], int head_index, int tail_index){
	if(head_index && tail_index == -1){
		printf("\nQueue is empty\n");
		return 1;
	}
		return 0;
}

int isFull(char array[MAX], int tail_index){
	if(tail_index== MAX-1){
		printf("Queue is full\n");
		return 1;
	}
	else
		return 0;
}
	

void enqueue(char array[MAX], char input, int *tail_index){ // insert
	if(isFull(array, *tail_index));
	else{
		*tail_index+=1; // increment tail by 1
		array[*tail_index] = input;
	}
}

char dequeue(char array[MAX], int *head_index, int *tail_index){ // remove
	if(isEmpty(array, *head_index, *tail_index));
	else if(*head_index == *tail_index){ // singe element in queue
		*head_index = -1;
		*tail_index = -1;
		return array[0];
	}
	else{
		*head_index+=1;
		return array[*head_index];
	}
		
		
	return 0;
}

void display(char array[MAX], int head_index, int tail_index){
	int i;
	printf("Queue: ");
	for(i=head_index+1; i<=tail_index; i++){
		printf("%c ", array[i]);
	}
	printf("\n");
}

int main(void){
	char queue[MAX];
	char input;
	int navigate=0;
	int head_index, tail_index;
	head_index = tail_index = -1; // exit variable	
	
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
				enqueue(queue, input, &tail_index);
				break;
		
		case 2:	printf("Retreived: %c\n", dequeue(queue, &head_index, &tail_index));
				break;
		
		case 3: display(queue, head_index, tail_index);
				break;
				
		case 4: break;
		}
	}
	
	return 0;
}
