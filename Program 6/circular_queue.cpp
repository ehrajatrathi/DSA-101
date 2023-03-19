#include<stdio.h>
#include<malloc.h>

struct queue{
	int data;
	queue *next;	
};

struct queue *front=NULL, *rear=NULL;
int val;

void enqueue(){
	printf("Enter the value: ");
	scanf("%d", &val);
	struct queue *newnode = (struct queue*) malloc(sizeof(struct queue));
	
	newnode->data = val;
	
	if(front == NULL){
		front = rear = newnode;
		front->next = rear->next = front;
	}
	else{
		rear->next = newnode;
		rear = newnode;
		rear->next = front;
	}
}


void dequeue(){
	if(front==NULL){
		printf("Queue underflow!!\n");
	}
	else{
		printf("%d dequeued", front->data);
		struct queue* temp = front;
		front = front->next;
		rear->next = front;
		free(temp);
	
	}
}

void display(){
	if(front==NULL)
		printf("Queue empty");
	else{
		struct queue *temp = front;
		do{
			printf("%d : ", temp->data);
			temp = temp->next;
		}while(temp != front);
	}
}


int main(){
	printf("1. Enqueue	\t2. Dequeue \t3. Display\n");
	int choice;
	
	while(1){
		printf("\nChoice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:		enqueue();
						break;
				
			case 3:		display();
						break;
						
			case 2: 	dequeue();
						break;
						
			default:	printf("Wrong input");						
		}
	}
}
