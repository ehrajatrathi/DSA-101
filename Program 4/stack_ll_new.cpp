// Code by KamalRaj sir

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	node *next;
};

int val;

struct node *top = NULL;
// int tail = 0;

char push_ele(char ele)
{
//	printf("Enter the element you want to push: ");
//	scanf("%d", &val);	

	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = ele;
	if (top == NULL)
	{

		top = newnode;
		newnode->next = NULL;
	}
	else
	{
		// top->next=newnode;
		newnode->next = top;
		top = newnode;
	}
	
	
}

//void push_ele()
//{
//	printf("Enter the element you want to push: ");
//	scanf("%d", &val);	
//
//	struct node *newnode;
//	newnode = (struct node *)malloc(sizeof(struct node));
//	newnode->data = val;
//	if (top == NULL)
//	{
//
//		top = newnode;
//		newnode->next = NULL;
//	}
//	else
//	{
//		// top->next=newnode;
//		newnode->next = top;
//		top = newnode;
//	}
//}

void pop_ele()
{
	if (top == NULL)
	{
		printf("Stack Underflow!!!\n\n");
	}
	
	else
	{
		struct node *temp = top;
		top = top->next;
		free(temp);
		printf("Element popped!");
	}
}

void display_ele()
{
	if (top == NULL)
	{
		printf("Stack Empty");
	}
	else
	{
		struct node *temp = top;

		while (temp != NULL)
		{
			printf("%c : ", temp->data);
			temp = temp->next;
		}
	}
}

int main()
{
	int choice;
	
	char exp[10] = {'a', '+', 'b', '*', 'c'};

	//printf("Infix is: %s", exp);
	
	int i = 0;
	
	//printf("%c", exp[i]);
	while(exp[i] != '\0'){
		printf("%c \n", exp[i]);
		if(exp[i] == '+' || exp[i] == '-'){
			///printf("%c", exp[i]);
			push_ele(exp[i]);
		}		
		else if(exp[i] == '*' || exp[i] == '/'){
			push_ele(exp[i]);
		}
		i++;
	}
	display_ele();
}

