#include <iostream>
#include <queue>
using namespace std;
//Definition of node
struct node{
	int data;
	int liss;
	node* left;
	node* right;
};
//Function to create new node
node* newNode(const int &newData){
	node* temp = new node;
	temp->data = newData;
	temp->liss = 0;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//Function to insert nodes in a complete binary tree
void insert(node* &root,int newData,queue <node*> &q){
	node* temp = newNode(newData);
	//If the root is null
	//make the new node root
	if(!root){
		root = temp;
		q.push(root);
		return;
	}
	//Get the front of the queue
	//to check if the node is complete
	node* front = q.front();
	if(!front->left){
		front->left = temp;
		q.push(front->left);
		return;
	}
	if(!front->right){
		front->right = temp;
		q.push(front->right);
		//Node is complete so pop it from the queue
		q.pop();
		return;
	}
}
//Function to do the inorder traversal of the tree
void printInorder(node* root){
	if(!root)
		return;
	printInorder(root->left);
	cout<<root->data<<"\t";
	printInorder(root->right);
}
int liss(node* root){
	if(!root)
		return 0;
	if(root->liss)
		return root->liss;
	int excl_liss = liss(root->left) + liss(root->right);
	int incl_liss = 1;
	if(root->left)
		incl_liss += liss(root->left->left) + liss(root->left->right);
	if(root->right)
		incl_liss += liss(root->right->left) + liss(root->right->right);
	root->liss = max(incl_liss, excl_liss);
	return root->liss;
}
int main(){
	queue <node*> q;
	node* root = NULL;
	for(int i = 1; i<11; i++)
		insert(root,i,q);
	printInorder(root);
	int count = liss(root);
	cout<<endl;
	cout<<count<<endl;
	return 0;
}