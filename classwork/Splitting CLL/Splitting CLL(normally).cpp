#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	node* next;
};

struct node* head = NULL;
int value, size=0;

void insertNode(){
	struct node* newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL){
		printf("Enter the first element: ");
		scanf("%d", &value);		
		newnode->data = value;
		head = newnode;
		newnode->next = head;		
		size++;
	}
	else{
		printf("Enter value: ");
		scanf("%d", &value);
		newnode->data = value;
		struct node* temp = head;		
		while(temp->next != head){
			temp = temp->next;			
		}
		newnode->next = temp->next;
		temp->next = newnode;
		//newnode->next = head;				
		size++;
	}		
}

void displayNode(){
	int i = 0;
	struct node* temp = head;
	while(i<size){
		printf("%d: ", temp->data);
		temp = temp->next;
		i++;
	}
}


void splitList(){
	if(size==1){
		printf("Cannot be splitted!");
	}
	else{
		int newSize = size/2;	
//		printf("\nNew size is %d\n", newSize);
		struct node *head2 = NULL, *temp = head;
		int i = 0; 
		while(i<newSize-1){
			temp = temp->next;
			i++;
		}
		head2 = temp->next;
		temp->next = head;
		
		temp = head2;
		while(temp->next != head)
			temp = temp->next;
			
		temp->next = head2;
		
		printf("First list is \n");
		temp = head;
		
		do{
			printf("%d : ", temp->data);
			temp = temp->next;
			
		}
		while(temp != head);	
		
//		printf("\nHead2 is %d\n", head2->data);
		printf("\n\nSecond list is \n");
		temp = head2;
		do{
			printf("%d : ", temp->data);
			temp = temp->next;
		}
		while(temp != head2);					
	}
}

int main(){
	int choice;
	printf("1. Add Node \n2. Display Node \3. Split node");
	while(1){
		printf("\nChoice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1	:	insertNode();
						displayNode();
						break;
						
			case 2	:	displayNode();
						break;
						
			case 3	:	splitList();
						break;
						
			default	:	printf("\nEnter correct value!!\n");
		}
	}
}

