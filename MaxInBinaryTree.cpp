#include <iostream>
using namespace std;
#define MIN -999999		//Macro for minimum possible no
//Definition of the node
struct node{
	int data;
	node* left;
	node* right;
};
//Function to create a node
node* createNode(int newData){
	node* temp = NULL;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//Function to insert node at left side
void insertLeft(node* &root,int newData){
	node* temp = createNode(newData);
	root->left = temp;
}
//Function to insert node at right side
void insertRight(node* &root,int newData){
	node* temp = createNode(newData);
	root->right = temp;
}
/*int maxm(node* &root){
	if(!root)
		return MIN;
	int maxr = root->data;		
	int maxl = maxm(root->left);	//stores max of left subtree
	int maxrt = maxm(root->right);	//stores max of right subtree
	if(maxr<maxl)
		maxr = maxl;
	if(maxr<maxrt)
		maxr = maxrt;
	return maxrt;	
}*/

int main(){
	node* head = createNode(2);
	insertLeft(head,7);
	insertRight(head,5);
	insertRight(head->left,6);
	insertLeft(head->left->right,1);
	insertRight(head->left->right,11);
	insertRight(head->right,9);
	insertLeft(head->right->right,4);
	//cout<<maxm(head)<<endl;
	return 0;
}
