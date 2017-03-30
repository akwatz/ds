#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//Definiton of the node
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
//Function to return the preorder traversal of the tree
void preOrder(node* root,string &s){
	if(!root)
		return;
	s += root->data;
	preOrder(root->left,s);
	preOrder(root->right,s);
}
//Function to return the inorder traversal of the tree
void inOrder(node* root,string &s){
	if(!root)
		return;
	inOrder(root->left,s);
	s += to_string(root->data);
	inOrder(root->right,s);
}
//Function to tell if the given tree is subtree or not
bool isSubtree(node* t,node* s){
	string tI;
	inOrder(t,tI);
	cout<<tI<<endl;
	string sI;
	inOrder(s,sI);
	cout<<sI<<endl;
	//Fetch the begining of the substring
	int i = tI.find(sI[0]); 
	//Fetch the ending of the substring
	int j = tI.find(sI[sI.length() - 1]);
	//Form the substring
	tI = tI.substr(i,j);
	cout<<tI<<endl;
	if(tI.compare(sI))
		return false;

	return true;
}
int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
    return 0;
}