//CLL Using SLL
#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	node* next;
};

int value, size=0, pos;

struct node* head = NULL;


void insertNode(){
	if(head==NULL){
		struct node* newnode;
		newnode = (struct node*) malloc(sizeof(struct node));		
		printf("\nEnter value: ");
		scanf("%d", &value);
		newnode->data = value;		
		head = newnode;
		newnode->next = head;
		size++;
//		struct node* newnode;
//		newnode=(struct node*) malloc(sizeof(struct node));
	}
	else{
		printf("Enter the position you want to enter value: ");
		scanf("%d", &pos);
		if(pos==1){
			struct node *newnode, *temp;
			newnode = (struct node*) malloc(sizeof(struct node));
			temp = head;
			while(temp->next != head){
				temp = temp->next;
			}
			printf("Enter value(first node): ");
			scanf("%d", &value);
			newnode->data = value;
			temp->next = newnode;
			newnode->next = head;
			head = newnode;
			size++;
		}
		else if(pos == size){
			struct node *newnode, *temp;
			newnode = (struct node*) malloc(sizeof(struct node));
			temp = head;			
			while(temp->next != head){
				temp = temp->next;
			}
			//printf("The last value is : %d\n", temp->data);
			printf("Enter value(last node)): ");
			scanf("%d", &value);
			newnode->data = value;
			temp->next = newnode;
			newnode->next = head;
			size++;
		}
		else if(pos>size){
			printf("\n\nPosition out of bound!!\n\n");
		}
		else{
			struct node *newnode, *temp;
			newnode = (struct node*) malloc(sizeof(struct node));
			temp = head;
			int i = 1;
			while(i<pos){
				temp = temp->next;
				i++;
			}
			printf("Enter value(%d node)): ", i);
			scanf("%d", &value);
			newnode->data = value;
			newnode->next = temp->next;
			temp->next = newnode;
			size++;
		}
	}
}

void deleteNode(){
	if(head == NULL){
		printf("\nNo node found to delete!!\n");
	}
	else if(size == 1 || head->next == head){
		struct node* temp;
		temp = head;
		printf("Node value %d deleted", temp->data);
		head = NULL;
		free(temp);		
		size--;
	}
	else{
		printf("Enter the position you want to delete data: ");
		scanf("%d", &pos);
		if(pos==1){
			struct node *temp;
			temp = head;
			while(temp->next != head){
				temp = temp->next;
			}			
			head = head->next;
			temp->next = head;
			size--;
		}
		else if(pos>size){
			printf("\nPosition out of bound!!\n");
		}
		else{
			struct node *temp, *prev;
			temp = prev = head;
			int i = 0;
			while(i<pos-1){
				prev = temp;
				temp = temp->next;
				i++;
			}
			prev->next = temp->next;
			printf("\nNode value %d deleted\n", temp->data);
			free(temp);
			size--;	
		}
		
		
	}
}

void searchNode(){
	
}

void displayNode(){
	struct node* temp;
	temp = head;
//	printf("head is = %d\n", head->data);
	if(size == 0 && head == NULL){
		printf("\nEmpty List!!\n");
	}
	else if(size == 1){
		printf("%d", head->data);
	}
	else{
		int i = 1;
//		while(temp->next != head){
//			printf("%d : ", temp->data);
//			temp = temp->next;
//		}	
		while(i<=size){
			printf("%d : ", temp->data);
			temp = temp->next;
			i++;
		}
		//printf("Hoo: the value is %d", temp->data);
	}
	
}


int main(){
	int choice;
	printf("1.Insert \n2.Delete \n3.Search \n4.Display\n\n");
	while(1){
		
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:		insertNode();
						displayNode();
						break;
						
			case 2: 	deleteNode();
						displayNode();
						break;
						
			case 3:		searchNode();
						break;
						
			case 4: 	displayNode();
						break;
						
			default:	printf("Enter correct value");
		}
	}
}
