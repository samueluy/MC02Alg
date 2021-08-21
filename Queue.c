#include <stdio.h>
#define MAX 3 // fix the size to 255

// still need to make it a circular array

int isEmpty(int head_index, int tail_index){
	if(head_index==-1 && tail_index==-1){
		printf("\nQueue is empty\n");
		return 1;
	}
		return 0;
}

int isFull(int tail_index, int size){
	if(size == MAX){
		printf("Queue is full\n");
		return 1;
	}
	else
		return 0;
}
	
void enqueue(char array[MAX], char input, int *tail_index, int *size){ // insert
	if(isFull(*tail_index, *size));
	else if (!isFull(*tail_index, *size) && *tail_index == MAX-1){ // return to index 0 (circular array)
		*tail_index+=1;
		array[*tail_index%MAX] = input;
		*size+=1;
	}
	else{
		*tail_index+=1; // increment tail by 1
		array[*tail_index] = input;
		*size+=1;
	}
}

char dequeue(char array[MAX], int *head_index, int *tail_index, int *size){
	if(isEmpty(*head_index, *tail_index));
	else if(*size==1){ // single element in queue
		*size=0;
		*head_index = -1;
		*tail_index = -1;
		return array[0];
	}
	else{
		*size-=1;
		*head_index+=1;
		return array[*head_index];
	}
	
	return 0;
}

void display(char array[MAX], int head_index, int tail_index, int size){
	int i;
	printf("\nElements in Circular Queue are: ");
    if (tail_index >= head_index)
    {
        for (i = head_index; i <= tail_index; i++)
            printf("%d ",array[i]);
    }
    else
    {
        for (i = head_index; i < size; i++)
            printf("%d ", array[i]);
 
        for (i = 0; i <= tail_index; i++)
            printf("%d ", array[i]);
    }
    printf("\n\n");
	/*
	int i;
	printf("\nQueue: ");
	for(i=head_index; i<=(size+head_index); i++){
		if(i > MAX){
			printf("%c ", array[i%MAX]);
		}
		else
			printf("%c ", array[i]);
	}
	printf("\n");*/
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
				printf("head: %d\n", head_index+1);
				printf("tail: %d\n", tail_index);
				printf("size: %d\n", size);
				break;
				
		case 4: break;
		}
	}
	
	return 0;
}
