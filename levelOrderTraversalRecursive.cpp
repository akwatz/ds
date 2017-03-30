#include <iostream>
#include <queue>
using namespace std;
//definition of node
struct node{
	int data;
	node* left;
	node* right;
};
//function to create new node
node* newNode(int newData){
	node* temp = new node;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printLevelOrder(queue <node*> &q){
	if(q.empty())
		return;
	node* temp = q.front();
	q.pop();
	cout<<temp->data<<"\t";
	if(temp->left)
		q.push(temp->left);
	if(temp->right)
		q.push(temp->right);
	printLevelOrder(q);
}
int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(1);
  	root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 	queue <node*> q;
 	q.push(root);
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(q);
    return 0;
}