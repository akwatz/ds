#include <iostream>
using namespace std;
//Definition of the node
struct node{
	int data;
	node* left;
	node* right;
	node* nextRight;
};
//Function to create new node
node* newNode(int newData){
	node* temp = new node;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//Function to print the inorder traversal of the tree
void printInorder(node* root){
	if(!root)
		return;
	printInorder(root->left);
	cout<<root->data<<"\t";
	printInorder(root->right);
}
bool isComplete(node* root){
	if(!root)
		return true;
	if(!root->left && !root->right)
		return true;
	if(!root->left || !root->right)
		return false;
	return (isComplete(root->left) && isComplete(root->right));
}
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	//root->right->right = newNode(7);
	printInorder(root);
	cout<<endl;
	cout<<isComplete(root)<<endl;
	return 0;
}	