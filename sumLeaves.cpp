#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
//Definition of node
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
//Function to calculate height of the tree
int height(node* root){
	if(!root)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}
//Function to calculate the power of 10
int pow(int exp){
	int base = 1;
	while(exp--)
		base = base*10;
	return base;
}
//Function to calculate the path sum of leaves
void sum(node* root, int &pathSum, int arr[], int index){
	if(!root)
		return;
	if(!root->left && !root->right){
		arr[index] = root->data;
		for(int i = 0, j = index; i<=index; i++,j--)
			pathSum += arr[i] * pow(j);
		index--;
		return;
	}
	arr[index] = root->data;
	sum(root->left, pathSum, arr, index + 1);
	sum(root->right, pathSum, arr, index + 1);
	index--;
}
//wrapper function to calculate the path sum of leaves to root
int sumLeaves(node* root){
	int ht = height(root);
	int arr[ht];
	int index = 0;
	int pathSum(0);
	sum(root, pathSum, arr, index);
	return pathSum;
}
int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    printf("Sum of all paths is %d", sumLeaves(root));
    cout<<endl;
    return 0;
}