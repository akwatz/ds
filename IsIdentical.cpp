#include <iostream>
#include <stack>
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
bool IsIndentical(node* root1,node* root2){
	if(!root1 && root2)
		return false;
	if(root1 && !root2)
		return false;
	if(!root1 && !root2)
		return true;
	if(root1->data != root2->data)
		return false;
	if(!IsIndentical(root1->left,root2->left))
		return false;
	if(!IsIndentical(root1->right,root2->right))
		return false;
	return true;
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
    node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->right = newNode(7);
    cout<<IsIndentical(root,root1)<<endl;
    return 0;
}