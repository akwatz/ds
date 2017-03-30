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
//Declaration of the utility function
void connectRecur(node*);
//Function to connect the nodes
void connect(node* root){
	root->nextRight = NULL;
	connectRecur(root);
}
//Definition of the utility function
void connectRecur(node* root){
	if(!root)
		return;
	if(root->left)
		root->left->nextRight = root->right;
	if(root->right)
		root->right->nextRight = root->nextRight?root->nextRight->left:NULL;
	connectRecur(root->left);
	connectRecur(root->right);
}
void printLevel(node* root){
	if(!root)
		return;
	node* temp = root;
	while(temp){
		cout<<temp->data<<"\t";
		temp = temp->nextRight;
	}
	cout<<endl;
	printLevel(root->left);
}
void printInorder(node* root){
	if(!root)
		return;
	printInorder(root->left);
	cout<<root->data<<"\t";
	printInorder(root->right);
}
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	connect(root);
	printInorder(root);
	cout<<endl;
	printLevel(root);
	return 0;
}	