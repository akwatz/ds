#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
 
// Structure of a tree node
struct Node{
    char key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node *newNode(char item){
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(Node* root, string &s){
    if(!root)
        return;
    inorder(root->left, s);
    s += root->data;
    inorder(root->right, s);
}
void preorder(Node* root, string &s){
    if(!root)
        return;
    s += root->dta;
    preorder(root->left, s);
    preorder(root->right, s);
}
bool isSubtree(Node* parent, Node* child){
    string inP = "";
    string inC = "";
    string preP = "";
    string preC = "";

}
int main(){
    Node *T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node *S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
 
    return 0;
}