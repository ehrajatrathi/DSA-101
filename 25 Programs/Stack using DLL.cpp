#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next, *prev;
};

struct node* head = NULL;
int val;

void push(){
	printf("Enter the element: ");
	scanf("%d", &val);
	
	if(head==NULL){		
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = val;
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;		
	}
	else{
		struct node* newnode = (struct node*) malloc(sizeof(struct node));
		newnode->data = val;
		newnode->next = head;
		newnode->prev = NULL;
		
		head->prev = newnode;
		head = newnode;
	}
}

void pop(){
	if(head == NULL)
		printf("Stack Underflow");
	else if(head->next == NULL){
		printf("%d popped!\n", head->data);
		struct node* temp = head;
		head = NULL;		
		free(temp);
	}
	else{
		printf("%d popped!\n", head->data);
		struct node* temp = head;
		head = head->next;
		head->prev = NULL;
		
		free(temp);
	}	
}

void display(){
	if(head == NULL){
		printf("Nothing to display\n");
	}
	else{
		struct node* temp = head;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
}


int main(){
	printf("1. Push \n2. Pop \n3. Display\n\n");
	int choice;
	while(1){
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			
		
			
			case 1:	push();
					break;
					
			case 2:	pop();
					break;
					
			case 3: display();
					break;
					
			default: printf("Enter correct option!");
		}
	}
}
