//Binary Serach Tree

#include<stdio.h>
#include<malloc.h>

struct BSTNode{
	int data;
	struct BSTNode *left, *right;
};

//struct BSTNode *root;

struct BSTNode* insertNode(BSTNode *root, int data){
	if(root == NULL){
		root = (struct BSTNode*)malloc(sizeof(struct BSTNode));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if(data <= root->data){
		root->left = insertNode(root->left, data);
	}
	else{
		root->right = insertNode(root->right, data);
	}
	return root;
}

void inOrder(struct BSTNode* root){
	if (root==NULL)
		return;
	else{
		inOrder(root->left)	;
		printf("%d ", root->data);
		inOrder(root->right);
	}
	
}


bool searchNode(struct BSTNode* root, int key){
	if(root == NULL)
		return false;
	else if(root->data == key)
		return true;
	else if(key >= root->data)
		searchNode(root->right, key);
	else
		searchNode(root->left, key);	
}


int main(){
	BSTNode *root = NULL;
	root = insertNode(root, 15);
	root = insertNode(root, 10);
	root = insertNode(root, 20);
	root = insertNode(root, 25);
	root = insertNode(root, 8);
	root = insertNode(root, 12);
	
	printf("Inorder traversal: \n");
	inOrder(root);
	
	int key;
	printf("\nEnter the key you want to search: ");
	scanf("%d", &key);
	if(searchNode(root, key))
		printf("Key Found");
	else
		printf("Key not found");
}
