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
//Function to calculate the sum of root to leaf
int sum(node* root,int value){
    if(!root)
        return 0;
    value = value*10 + root->data;
    if(!root->left && !root->right)
        return value;
    return sum(root->left,value) + sum(root->right,value);
}
//Wrapper function to calculate the sum of root to leaf
int sumLeaves(node* root){
    if(!root)
        return 0;
    return sum(root,0);
}
int main(){
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