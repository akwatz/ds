#include <iostream>
#include <string>
#include <queue>
using namespace std;
//defining the node
struct node{
	int data;
	node* left;
	node* right;
};
//Function to create new node
node* newNode(int newData){
	node* temp = new node;	//memory allocation for new node
	temp->data = newData;	//assigning the data in the node
	temp->left = NULL;		//setting the left child as null
	temp->right = NULL;		//setting the right child as null
	return temp;
}
//function to print level order line by line
void printLevelOrder(node* root){
	queue <node*> q;
	q.push(root);
	while(1){
		int nodeCount = q.size();
		if(!nodeCount)
			break;
		while(nodeCount > 0){
			node* temp = q.front();
			q.pop();
			cout<<temp->data<<"\t";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			nodeCount--;
		}
		cout<<endl;
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
