#include<stdio.h>
#include<malloc.h>

int queue[10];

int val;
int front=  -1,rear = -1;

//front = -1;

void enqueue(){
	
	if(rear==9){
		printf("Queue overflow!!\n");
	}
	else{
		printf("Enter the element you want to enque: ");
		scanf("%d", &val);		
		
		
		if(front == -1){	
			queue[0] = val;
			front++, rear++;
		}
		else{
			queue[++rear] = val;
		}	
	}
	
}


void dequeue(){	
	if(front==-1 || front> rear){
		printf("Queue underflow!!");
	}else{
		printf("%d dequeued!!", queue[front++]);		
		if(front>rear){
			printf("Queue reseted! ");
			front = rear = -1;
		}						
	}		
}

void display(){	
	if(front==-1){
		printf("Nothing to display");
	}else{
		val = front;
		while(val <= rear){			
			printf("%d: ", queue[val++]);			
		}	
	}	
}


int main(){
	printf("1. Enqueue \t2. Dequeue \t3. Display\n");
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
