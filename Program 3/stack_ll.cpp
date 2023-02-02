#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	node* next;
};

int val;

struct node *head, *top = NULL;
//int tail = 0;

void push_ele(){
	printf("Enter the element you want to push: ");
	scanf("%d", &val);
	
//	struct node* newnode;
//	newnode = (struct *node) malloc(sizeof(struct node));
	
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	newnode->data=val;
	if(head==NULL){
	
		newnode->next=NULL;
		top = head = newnode;
	}
	else{
		top->next=newnode;
		newnode->next = NULL;
		top = newnode;
	}
}

void pop_ele(){
	if(head == NULL){
		printf("Stack Underflow!!!\n\n");		
	}
	else if(head == top){
		struct node* temp = head;
		temp = head;
		head = top = NULL;
		free(temp);
		printf("Element popped!");
	}
	else{
		struct node* temp = head;
		while(temp->next != top){
			temp = temp->next;
		}

		top = temp;
		temp = temp->next;
		top->next = NULL;		
		temp = NULL;
		free(temp);
		printf("Element popped!");
	}
}


void display_ele(){
	if(head==NULL){
		printf("Stack Empty");
	}
	else{
		struct node* temp = head;
		
		while(temp!=NULL){
			printf("%d : ", temp->data);
			temp = temp->next;
		}		
	}
}

int main(){
	int choice;
	while(1){
		printf("\n1.Push \n2.Pop \n3.Display\n");
		scanf("%d", &choice);
		printf("\n\n");
		
		switch(choice){
			case 1:		push_ele();
						break;
						
			case 2:		pop_ele();
						break;
						
			case 3:		display_ele();
						break;
						
			default:	printf("Enter a valid choice!!!\n");
		}
	}
}
