#include <iostream>
#include <string>
using namespace std;
//defining the node
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
//declaring prototype for the function
void printGivenLevel(node*,int);
//function to calculate the height of the root
int height(node* root){
	if(!root)
		return 0;
	int lHeight = height(root->left);
	int rHeight = height(root->right);
	return (max(lHeight,rHeight) + 1);	
}
//function to print the level order traversaln 
void printLevelOrder(node* root){
	int ht = height(root);
	for(int i = 1;i <= ht;i++){
		printGivenLevel(root,i);
		cout<<endl;
	}
}

void printGivenLevel(node* root,int ht){
	if(!root)
		return;
	if(ht == 1){
		cout<<root->data<<"\t";
		return;
	}
	else if(ht > 1){
		printGivenLevel(root->left,ht-1);
		printGivenLevel(root->right,ht-1);
	}
}

int main()
{
    // Let us create binary tree shown in above diagram
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}
