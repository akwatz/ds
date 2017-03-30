#include <iostream>
using namespace std;
//Definition of the node
struct node{
  int data;
  struct node* left;
  struct node* right;
};
//Function to create new node
node* newNode(int data){
  struct node* temp = new node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
 
  return(temp);
}
//Function to create the mirror image of the tree
void mirror(node* root){
	if(!root)
		return;
	mirror(root->left);
	mirror(root->right);
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}
//Function to check if left or right subtree are structurally similar
bool isSame(node* n1,node* n2){
	if(!n1 && !n2)
		return true;
	if(n1 && n2 && isSame(n1->left,n2->left) && isSame(n1->right,n2->right))
		return true;
	else return false;
}
bool isFoldable(node* root){
	if(!root)
		return true;
	mirror(root->left);
	bool res = isSame(root->left,root->right);
	mirror(root->left);
	return res;
}
int main(){
  /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  //root->right->left  = newNode(4);
  root->left->right = newNode(5);
 
  if(isFoldable(root))
  	cout<<"\n tree is foldable"; 
  else
  	cout<<"\n tree is not foldable";

  return 0;
}