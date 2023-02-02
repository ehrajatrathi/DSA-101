#include<stdio.h>



int stack[100], top = 0, val;


void display_ele(){
	if(top==0){
		printf("Stack Empty!!!\n\n");
	}
	else{
		for(int i=0; i<top; i++){
			printf("%d : ", stack[i]);
		}
	}
}

void push_ele(){
	if(top==99){
		printf("Stack Overflow!!!\n\n");
	}
	else{
		printf("Enter the element you want to push: ");
		scanf("%d", &val);
		stack[top++]=val;
	}
}

void pop_ele(){
	if(top==0){
		printf("Stack Underflow!!!\n\n\n");
	}
	else{
		stack[top--]=NULL;
		printf("Element popped");
	}
}

int main(){
	
	int choice;
	
	while(1){
	
		printf("\n\nEnter 1 for pushing element \n\nEnter 2 for popping element \n\nEnter 3 for displaying elements \n\nChoice: ");
		scanf("%d", &choice);
		printf("\n\n");
		switch(choice){
			case 1:		push_ele();
						break;
						
			case 2:		pop_ele();
						break;
						
			case 3: 	display_ele();
						break;
						
			default: 	printf("Invalid choice, enter again. \n\n");
		}	
	}
	
	
	
}
