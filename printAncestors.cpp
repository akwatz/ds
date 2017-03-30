#include <iostream>
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
bool printAncestors(node* root,int key){
	if(!root)
		return false;
	if(root->data == key)
		return true;
	if(printAncestors(root->left,key) || printAncestors(root->right,key)){
		cout<<root->data<<"\t";
		return true;
	}
	return false;
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
 	printAncestors(root,5);
    return 0;
}