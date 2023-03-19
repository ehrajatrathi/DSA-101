//Binary Tree using linked list

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node* create(){
	int x;
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	
	printf("Enter data (-1 for no node): ");
	scanf("%d", &x);
	
	if(x==-1){
		return 0;
	}
	
	newnode->data = x;
	
	printf("Enter the left child of %d: \n", x);
	newnode->left = create();
	
	printf("Enter the right child of %d: \n", x);
	newnode->right = create();
	
	return newnode;
}


void inOrder(struct node* root){
	if(root == 0)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(struct node* root){
	if(root == 0)
		return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node* root){
	if(root == 0)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}

int main(){
	struct node* root;
	root = 0;
	root = create();
	
	printf("InOrder traversal: ");
	inOrder(root);
	
	printf("\nPreOrder traversal: ");
	preOrder(root);
	
	printf("\nPostOrder traversal: ");
	postOrder(root);
}
