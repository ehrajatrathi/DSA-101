#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	node* next;
};

struct node *front = NULL, *rear = NULL;
int val;

void enqueue(){
	
	printf("Enter the element you want to enque: ");
	scanf("%d", &val);
	
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = val;
	
	
	if(front == NULL){
		//printf("Queue empty");			
				
		front = rear = newnode;
		front->next = rear->next = NULL;
	}
	else{
		rear->next = newnode;
		rear = newnode;	
		rear->next = NULL;
	}
}


void dequeue(){	
	if(front==NULL){
		printf("Queue underflow!!");
	}else{
		printf("%d dequeued!!", front->data);
		struct node* temp = front;
		front = front->next;
		free(temp);	
	}	
	
}

void display(){
	
	if(front==NULL){
		printf("Nothing to display");
	}else{
		struct node* temp = front;
		while(temp != NULL){
			printf("%d: ", temp->data);
			temp = temp->next;
		}	
	}
	
}


int main(){
	printf("1. Enqueue \t2. Dequeu \t3. Display\n");
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
