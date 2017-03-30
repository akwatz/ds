#include <iostream>
#include <stdio.h>
using namespace std;

//Definition of node of tree
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

//Wrapper function to return the lca
void lcaUtility(node* root , int key1 , int key2 , bool &found , node* &LCA , node* prev){
    if(!root)
        return;
    if(root->data == key1){
        found = true;
        if(prev->data > key2)
            LCA = root;
        return;
    }
    if(!found){
        lcaUtility(root->left , key1 , key2 , found , LCA , root);
        lcaUtility(root->right , key1 , key2 , found , LCA , root);
    }
    if(LCA)
        return;
    if(prev->data > key2){
        LCA = root;
    }
    else
        return;
}

//Function to return the lca of the two nodes
node* lca(node* root , int key1 , int key2){
    node* LCA = NULL;
    bool found = false;
    lcaUtility(root , key1 , key2 , found , LCA , root);
    return LCA;
}
int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    return 0;
}