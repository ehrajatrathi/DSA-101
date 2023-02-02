#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
	node* prev;
	node* next;
	int data;
};

struct node* head=NULL;


int val;

void insertAtFront(){
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	
	printf("Enter the element: ");
	scanf("%d", &val);
	
	newnode->data=val;
	newnode->next=newnode->prev=NULL;
	
	if(head==NULL){		
		head=newnode;
	}
	else{
		head->prev = newnode;
		//head->next = NULL;
		newnode->next = head;
		newnode->prev = NULL;
		
		head=newnode;
	}
}


void insertAtEnd(){
	struct node* newnode;
	//newnode=(struct node*) malloc(sizeof(struct node));
	newnode=(struct node*) malloc(sizeof(struct node));
	
	printf("Enter the value: ");
	scanf("%d", &val);
	
	newnode->next = newnode->prev = NULL;
	newnode->data = val;
	
	if(head==NULL){
		head = newnode;
	}
	else{
		struct node* temp;
		temp=head;
		
		while(temp->next != NULL){
			temp=temp->next;
		}
		
		temp->next = newnode;
		newnode->prev = temp;
	}
}


int getSize(){
	int size = 0;
	struct node* temp;
	temp = head;
	
	if(head==NULL){
		return size;
	}
	else{
		while(temp != NULL){
			temp = temp->next;
			size++;
		}
	//	printf("The size is %d", size);
		return size;
		
	}
}

void insertAtMiddle(){
	int size = 0, pos;
	
	size = getSize();
	
	printf("Enter the position of the new element: ");
	scanf("%d", &pos);
	
	if(pos>size){
		printf("Enter correct position.");
	
	}
	else if(pos==1){
		insertAtFront();
	}
	else{
		struct node *temp, *newnode;
		temp = head;
		newnode=(struct node*) malloc(sizeof(struct node));
		//newnode->next = newnode->prev = NULL;
		for(int i = 1; i<=pos-1; i++){
			temp = temp->next;
		}
		printf("Enter the new element: ");
		scanf("%d", &val);
		printf("Reached\n");
		newnode->data = val;
		newnode->next = temp->prev->next;
		newnode->prev = temp->prev;
		temp->prev->next = newnode;
		temp->prev = newnode;
	}
}


void displayList(){
	struct node* temp;
	temp=head;
	while(temp != NULL){
		printf("%d : ", temp->data);
		temp=temp->next;
	}
}

void deleteKey(){
	struct node* temp;
	temp=head;
	int size = getSize(), key_deleted = 0, pos = 1;
	
	
	printf("Enter the element you want to delete: ");
	scanf("%d", &val);
	
	while(temp != NULL){
		if(temp->data == val){
			if(temp==head){
					head=temp->next;
					head->prev = NULL;					
					temp=NULL;
					free(temp);
					printf("Key found at position %d and deleted", pos);
					key_deleted=1;
					break;
			}
			printf("Element found at %d and deleted.", pos);
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp=NULL;
			free(temp);
			//printf("Key found at position %d and deleted", pos);
			key_deleted=1;
			break;	
		}
		else{
			temp = temp->next;
			pos++;
		}
	}
	if(key_deleted==0){
		printf("Key deleted not found");
	}
}


void searchKey(){
	struct node* temp;
	temp = head;
	
	int pos = 1, key_found = 0;
	printf("Enter the element you want to search: ");
	scanf("%d", &val);	
	
	while(temp != NULL){
		if(temp->data == val){
			printf("Key found at %d position", pos);
			key_found = 1;
			return;
		}
		else{
			temp = temp -> next;
			pos++;
		}
	}

	if(key_found==0){
		printf("Key not found");
	}	
}

int main(){
	int choice;
	
	while(1){
		
		printf("\n\n1.\tInsertAtFront \n2.\tInsertAtEnd \n3.\tInsertAtMiddle \n4.\tSearchKey \n5.\tDeleteKey \n6.\tDisplayList\n\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: insertAtFront();
					break;
					
			case 2: insertAtEnd();
					break;
					
			case 3: insertAtMiddle();
					break;
					
			case 4: searchKey();
					break;
					
			case 5: deleteKey();
					break;
					
			case 6: displayList();
					break;
		}	
	}
	
}
