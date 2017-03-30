#include <iostream>
#include <queue>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};

node* newNode(int newData){
	node* temp = new node;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printLevelOrder(node* root){
	if(!root)
		return;
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		cout<<temp->data<<"\t";
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	cout<<endl;
}

int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}