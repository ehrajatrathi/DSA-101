#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right, *left;
	int ht;
};

struct node *root = NULL;

struct node* create(int data){
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = data;
	newnode->right = newnode->left = NULL;
	return newnode;
}

int height(struct node* root){
	int lh, rh;
	if(root == NULL)
		return 0;
	if(root->left == NULL)
		lh = 0;
	else
		lh = 1 + root->left->ht;
		
	if(root->right == NULL)
		rh = 0;
	else
		rh = 1 + root->right->ht;
		
	if(lh>rh)
		return lh;
	else
		return rh;
}

struct node* rotate_left(struct node* root){
	printf("%d rotated LEFT!\n", root->data);
	
	struct node* right_child = root->right;
	root->right = right_child->left;
	right_child->left = root;
	
	root->ht = height(root);
	right_child->ht = height(right_child);
	
	return right_child;
}

struct  node* rotate_right(struct node* root){
	printf("%d rotated RIGHT!\n", root->data);
	
	struct node* left_child = root->left;
	root->left = left_child->right;
	left_child->right = root;
	
	root->ht = height(root);
	left_child->ht = height(left_child);
	
	return left_child;
}

int balance_factor(struct node* root){
	int lh, rh;
	if(root==NULL)
		return 0;
	if(root->left == NULL)
		lh = 0;
	else
		lh = 1 + root->left->ht;
		
	if(root->right == NULL)
		rh = 0;
	else
		rh = 1 + root->right->ht;
		
	return lh-rh;
}




struct node* insert(struct node* root, int data){
	if(root == NULL){
		struct node* newnode = create(data);
		root = newnode;
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
		
		if(balance_factor(root) == -2){
			if(data > root->right->data)
				root = rotate_left(root);
			else{
				root->right = rotate_right(root->right);
				root = rotate_left(root);
			}
		}
	}
	else{
		root->left = insert(root->left, data);
		
		if(balance_factor(root) == 2){
			if(data<root->left->data)
				root = rotate_right(root);
			else{
				root->left = rotate_left(root->left);
				root = rotate_right(root);
			}
		}
	}
	root->ht = height(root);
	return root;
}

void inOrder(struct node* root){
	if(root == NULL)
		return;
	inOrder(root->right);
	printf("%d ", root->data);
	inOrder(root->left);
}


int main(){
	int choice, data;
	
	while(1){
		printf("\n1. Insert\n2. InOrder \n\nChoice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:		printf("Enter data: ");
						scanf("%d", &data);
						root = insert(root, data);
						break;
					
			case 2:		printf("InOrder Traversal: \n");
						inOrder(root);
						break;
		}
	}
}
