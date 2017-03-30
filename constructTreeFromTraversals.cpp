#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//Definition of node 
struct node{
  char data;
  struct node* left;
  struct node* right;
};
//Function to create new node
struct node* newNode(char data){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
//Function to return index
int index(char inorder[], int size, int key){
	int i;
	for(i = 0; i <= size; i++)
		if(inorder[i] == key)
			break;
	return i;
}
node* buildTree(char inorder[], char preorder[], int start, int end, int &rootI){
	static int size = start + end;
	if(start > end)
		return NULL;
	rootI += 1;
	node* root = newNode(preorder[rootI]);
	int rootIndex = index(inorder, size, preorder[rootI]);
	root->left = buildTree(inorder, preorder, start, rootIndex - 1, rootI);
	root->right = buildTree(inorder, preorder, rootIndex + 1, end, rootI);
	return root;
}
//Function to print inorder traversal of tree
void printInorder(struct node* node){
  if (node == NULL)
     return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%c ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
//Main function
int main(){
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  int rootI = -1;
  struct node *root = buildTree(in, pre, 0, len - 1, rootI);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
}