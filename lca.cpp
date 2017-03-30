#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int data;
};
 
// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
//Function to find if the given data is present in the binary tree
bool find(Node* root, int data){
    if(!root)
        return false;
    if(root->data == data)
        return true;
    return(find(root->left, data) || find(root->right, data));
}
//Function to return the lca of the two Nodes
Node* findLca(Node* root, int data1, int data2){
    if(!root)
        return NULL;
    if(root->data == data1 || root->data == data2)
        return root;
    Node* lca_l = findLca(root->left, data1, data2);
    Node* lca_r = findLca(root->right, data1, data2);
    if(lca_l && lca_r)
        return root;
    if(lca_l)
        return lca_l;
    if(lca_r)
        return lca_r;
}
int findLCA(Node* root, int data1, int data2){
    if(!root)
        return 0;
    Node* lca = findLca(root, data1, data2);
    bool val1(false),val2(false);
    val1 = find(root,data1);
    val2 = find(root,data2);
    if(val1 && val2)
        return lca->data;
    return 0;
}
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}