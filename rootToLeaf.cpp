#include <iostream>
#include <string>
using namespace std;
//Structure of the node
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
void rootToLeaf(node*root,string rootLeaf){
    if(!root)
        cout<<rootLeaf<<endl;
    else{
        string temp = rootLeaf + " ";
        temp += std::to_string(root->data);
        rootToLeaf(root->left,temp);
        rootToLeaf(root->right,temp);
    }
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    string rootLeaf;
    cout<<"Root to leaf path of binary tree is \n";
    rootToLeaf(root,rootLeaf);
 	cout<<endl;
    return 0;
}