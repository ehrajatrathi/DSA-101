#include<stdio.h>
#include<stdlib.h> 
#include<malloc.h>
#include<conio.h>


struct node{
	int data;
	node* next;	
};


int val;

struct node* head = NULL;

void insertAtFront(){
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	
	printf("Enter the element: ");
	scanf("%d", &val);
	
	newnode->data = val;
	
	if(head==NULL){
		newnode->next = NULL;
		head = newnode;
	}
	else{
		newnode->next=head;
		head=newnode;
	}
}


void insertAtLast(){
	struct node* newnode;
	newnode=(struct node*) malloc(sizeof(struct node));
	
	printf("Enter the element to insert: ");
	scanf("%d", &val);
	newnode->data=val;
	newnode->next=NULL;
	
	if(head==NULL){
		newnode->next=NULL;
		head=newnode;
	}
	else{
		struct node* temp;
		temp = head;
		while(temp->next != NULL){
			temp=temp->next;
	}
	temp->next=newnode;
		
 }
}


int calcListSize(){
	struct node* temp;
	temp=head;
	
	int size=0;
	if(head==NULL)
		return size;
	else{
		while(temp!=NULL){
			temp=temp->next;
			size++;
		}
		//printf("\nThe size of the list is %d\n", size)	;
		return size;
	}

}


void searchKey(){
	struct node* temp;
	temp=head;
	int key, pos=1, key_found=0;
	printf("Enter the key you want to search: ");
	scanf("%d", &key);
	
	while(temp->next!=NULL){
		if(temp->data==key){
			printf("Key found at:  %d", pos, " position");
			key_found=1;
		}
		temp=temp->	next;
		pos++;
	}
	if(key_found!=1){
		printf("Key not found");
	}
}


void deleteKey(){
	struct node
	 *temp, *prev;
	prev=temp=head;
	
	int key, pos=1, key_deleted=0;
	
	printf("Enter the key you want to delete: ");
	scanf("%d", &key);
	
	while(temp != NULL){
		if(temp->data==key)
		{															
				if(temp==head){
					head=temp->next;					
					temp=NULL;
					free(temp);
					printf("Key found at position %d and deleted", pos);
					key_deleted=1;
					break;
				}				
				prev->next=temp->next;				
				temp=NULL;
				free(temp);
				printf("Key found at position %d and deleted", pos);
				key_deleted=1;
				break;	
		}						
		prev=temp;
		temp=temp->next;
		pos++;
	}
	if(key_deleted==0){
		printf("Key deleted not found");
	}
}


void insertAtMiddle(){
	
	int size = calcListSize(), pos, i;
	//printf("The size is %d \n ", size);
	printf("Enter the position you want to put it in: ");
	scanf("%d", &pos);
	if(pos==1){
		insertAtFront();
	}
	else if(pos>size){
		printf("Enter correct value\n");		
	}
	else{
		struct node* temp=head;
		
		if(head==NULL)
		{
			printf("Empty List");
		}
		else{
			struct node* newnode;
			newnode=(struct node*) malloc(sizeof(struct node));
			
			
			printf("Enter the element: ");
			scanf("%d", &val);
			
			newnode->data=val;
			
			for(i=1; i<pos-1; i++){
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;
			
					
			
		}
		
		
		
	}
}


void displayList(){
	struct node* temp;
	
	temp = head;
	while(temp!=NULL){
		printf("%d : ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main(){
	int choice;
    while(1){
    	printf("\n\n\n1.\tInsertAtFirst  \n2.\tInsertAtLast \n3.\tInsertAtMiddle \n4.\tSearchKey \n5.\tDeleteKey  \n.6\tDisplay \n7.\tExit\n\n\n");
    	scanf("%d", &choice);
    	switch(choice){
    		case 1:		insertAtFront();
    					break;
    		
    		case 2: 	insertAtLast();
    					break;
    		
    		case 3: 	insertAtMiddle();
						break;
						
			case 4: 	searchKey();
						break;
									
			case 5: 	deleteKey();
						break;
						
			case 6: 	displayList();
						break;
						
			case 7: 	exit(0);
			
			default:	printf("Please enter a valid choice");    		
		}
	}
	
	return 0;
}
