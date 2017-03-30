#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
//Definition of node
struct Node{
	int data;
	Node* left;
	Node* right;
};
//Function to create new node
Node* newNode(const int &newData){
	Node* temp = new Node;
	temp->data = newData;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void print(struct Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}
//Function to delete the nodes which lie on the path
//whose sum is less than k
bool prune(Node* &root,int k,int sum){
	if(!root->left && !root->right){
		if(k + root->data > sum){
			delete(root);
			return true;
			//cout<<root->data<<"deleted";
		}
	}
	bool remove = false,remove_l = false,remove_r = false;
	if(root->left){
		remove_l = prune(root->left, k, sum + root->data);
		if(remove_l)
			root->left = NULL;
	}
	if(root->right){
		remove_r = prune(root->right, k, sum + root->data);
		if(remove_r)
			root->right = NULL;
	}
	if(root->left && root->right)
		remove = remove_l && remove_r;
	else if(root->left)
		remove = remove_l;
	else
		remove = remove_r;
	if(remove)
		delete(root);
	return remove;
}
int main()
{
    int k = 45;
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
    printf("Tree before truncation\n");
    print(root);
    bool b = prune(root, k, 0); // k is 45
    printf("\n\nTree after truncation\n");
    print(root);
    cout<<endl;
    return 0;
}