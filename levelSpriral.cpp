#include <iostream>
using namespace std;
//Structure of the node
struct node{
	int data;
	node* left;
	node* right;
};
//Function to create new node
node* newNode(int newData){
	node* temp = new node;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
//Function to calculate the height of the tree
int height(node* root){
	if(!root)
		return 0;
	return (max(height(root->left),height(root->right))+1);
}
//Prototype of the function to print the given level
void printGivenLevel(node*,int ,int);
//Function to print level order traversal in spiral way
void printLevelSpiral(node* root){
	int ht = height(root);
	bool ltr = true;
	for(int i = 1;i<=ht;i++){
		printGivenLevel(root,i,ltr);
		ltr = !ltr;
	}
}
//Function to print the given level
void printGivenLevel(node* root,int i,int ltr){
	if(i==1)
		cout<<root->data<<"\t";
	else if(i>1){
		if(ltr){
			printGivenLevel(root->right,i-1,ltr);
			printGivenLevel(root->left,i-1,ltr);	
		}
		else{
			printGivenLevel(root->left,i-1,ltr);
			printGivenLevel(root->right,i-1,ltr);
		}
	}
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout<<"Spiral Order traversal of binary tree is \n";
    printLevelSpiral(root);
 	cout<<endl;
    return 0;
}
