#include <iostream>
#include <queue>
using namespace std;
//Definition of node
struct node{
	int data;
	node* left;
	node* right;
};
//Function to create new node
node* newNode(const int &newData){
	node* temp = new node;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//Function to insert nodes in a complete binary tree
void insert(node* &root,int newData,queue <node*> &q){
	node* temp = newNode(newData);
	if(!root){
		root = temp;
		q.push(root);
		return;
	}
	node* front = q.front();
	if(!front->left){
		front->left = temp;
		q.push(front->left);
		return;
	}
	if(!front->right){
		front->right = temp;
		q.push(front->right);
		q.pop();
		return;
	}
}
void printInorder(node* root){
	if(!root)
		return;
	printInorder(root->left);
	cout<<root->data<<"\t";
	printInorder(root->right);
}
//Function to find the inorder successor
node* inorderSuccessor(node* root){
	if(root->right){
		root = root->right;
		while(root->left)
			root = root->left;
		return root;
	}
	return NULL;
}
//Function to find the inorder predecessor 
node* inorderPredecessor(node* root){
	if(root->left){
		root = root->left;
		while(root->right)
			root = root->right;
		return root;
	}
	return NULL;
}
//Utility function to convert tree int linked list
void Double(node* &root){
	if(!root)
		return;
	if(root->left){
		Double(root->left);
		node* temp = inorderPredecessor(root);
		temp->right = root;
		root->left = temp;
	}
	if(root->right){
		Double(root->right);
		node* temp = inorderSuccessor(root);
		temp->left = root;
		root->right = temp;
	}
}
//Function to convert tree into doubly linked list
void makeDouble(node* &root){
	if(!root)
		return;
	Double(root);
	while(root->left)
		root = root->left;

}
int main(){
	queue <node*> q;
	node* root = NULL;
	for(int i = 1; i<11; i++)
		insert(root,i,q);
	printInorder(root);
	cout<<endl;
	makeDouble(root);
	while(root){
		cout<<root->data<<"\t";
		root = root->right;
	}
	cout<<endl;
	return 0;
}