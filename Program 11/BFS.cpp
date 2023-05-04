#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node* next;
};

struct node *front = NULL, *rear = NULL;


int enqueue(int val){
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = val;
	if(front == NULL){
		front = rear = newnode;
		front->next = rear->next = NULL;
	}
	else{
		rear->next = newnode;
		rear = newnode;
		rear->next = NULL;
	}		
}

int dequeue(){
	if(front == NULL){
		printf("Queue underflow");
		//return -404
		
	}
		
	else{
		//printf("%d dequeud!!", front->data);
		int val = front->data;		
		struct node* temp = front;
		front = front->next;
		free(temp);	
		return val;
	}
}


void display(){
	if(front == NULL)
		printf("Nothing to display");
	else{
		struct node* temp = front;
		while(temp != NULL){
			printf("%d:", temp->data);
			temp = temp->next;
		}
	}
}

int isEmpty(){
	if(front == NULL)
		return 0;
}


int main(){
	//BFS Implementation
	int node;
	int i = 3;
	int visited[5] = {0,0,0,0,0};
	
	int a[5][5] = {
		{0,1,1,1,1},
		{1,0,0,0,0},
		{1,0,0,1,0},
		{1,0,1,0,1},
		{1,0,0,0,0}
	};
	printf("Visited nodes: ");
	printf("%d ", i);
	visited[i] = 1;
	enqueue(i);
	while(isEmpty() != 0){
		int node = dequeue();		
		for(int j = 0; j < 5; j++){
			if(a[node][j] == 1 && visited[j] == 0){
				printf("%d ", j);
				visited[j] = 1;
				enqueue(j);
			}
		}
	}
	
}
