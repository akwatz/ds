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
int main(){
	queue <node*> q;
	node* root = NULL;
	for(int i = 1; i<11; i++)
		insert(root,i,q);
	printInorder(root);
	cout<<endl;
	return 0;
}