//CLL using DLL
#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	node *prev, *next;		
};

struct node* head = NULL;
int value, pos, size=0;


void insertNode(){
	struct node* newnode;
	newnode = (struct node*) malloc(sizeof(struct node));	
	
	if(head==NULL){				
		printf("Enter value: ");
		scanf("%d", &value);
		newnode->data = value;
		head = newnode;
		head->next = head;
		head->prev = head;				
		size++;
	}
	else{
		printf("Enter the position: ");
		scanf("%d", &pos);
		printf("Enter value: ");
		scanf("%d", &value);
		newnode->data = value;
		if(pos==1){						
//			struct node* temp;
//			temp = head;
			newnode->next = head;
			newnode->prev = head->prev;
			head = newnode;
			size++;
		}
		else if(pos == size){
			head->prev->next = newnode;
			newnode->prev = head->prev;
			head->prev = newnode;
			newnode->next = head;
			size++;			
		}
		else if(pos>size){
			printf("\nPosition out of bound!!\n");
		}
		else{			
			int i = 1;
			struct node* temp = head;
			while(i<pos-1){
				temp = temp->next;
				i++;
			}
			newnode->prev = temp;
			newnode->next = temp->next;
			temp->next = newnode;
			newnode->next->prev = temp;
			size++;
		}
	}
}

void deleteNode(){
	if(head == NULL){
		printf("List Empty");
	}
	else if(size == 1){
		struct node* temp = head;
		printf("\nNode value %d deleted\n", head->data);
		head = NULL;
		free(temp);
		size--;
	}
	else{
		printf("Enter the position(to delete): ");
		scanf("%d", &pos);		
		if(pos == 1){				
			struct node* temp=head;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			printf("\nNode value %d deleted\n", head->data);
			head = head->next;
			free(temp);
			size--;
		}
		else if(pos==size){
			struct node* temp = head->prev;
			temp->prev->next = head;
			head->prev = temp->prev;
			free(temp);
			size--;
		}
		else if(pos>size){
			printf("Position out of bounds");
		}
		else{
			int i = 0;
			struct node* temp=head;
			while(i<pos-1){
				temp = temp->next;
				i++;
			}
			printf("\nNode value %d deleted\n", temp->data);
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			size--;
		}
		
	}
}

void displayNode(){
	if(size == 0){
		printf("List Empty!!");
	}
	else if(size == 1){
		printf("%d: ", head->data);
	}
	else{
		struct node* temp;
		temp = head;
		int i = 0;
		while(i<size){
			printf("%d : ", temp->data);
			i++;
			temp = temp->next;
		}	
	}
	
}

int main(){
	int choice;
	printf("1. Insert \n2. Delete \n3. Display\n\n");
	
	while(1){
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:		insertNode();
						displayNode();
						break;
						
			case 2:		deleteNode();
						displayNode();
						break;
				
			case 3: 	displayNode();
						break;
						
			default: 	printf("Enter correct option");
					
		}
	}
}
