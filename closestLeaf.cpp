// A C++ program to find the closesr leaf of a given key in Binary Tree
#include <iostream>
#include <climits>
using namespace std;
#define MAX 99999
/* A binary tree Node has key, pocharer to left and right children */
struct Node{
    char key;
    struct Node* left, *right;
};
 
/* Helper function that allocates a new node with the
   given key and NULL left and right pocharers. */
Node *newNode(char k){
    Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
int findLeaf(Node* root){
    if(!root)
        return MAX;
    if(!root->left && !root->right)
        return 0;
    return 1 + min(findLeaf(root->left), findLeaf(root->right));
}
//Function to find the closest leaf to the specific node
bool findClosest(Node* root, int key,int &closest){
    if(!root)
        return false;
    if(key == root->key){
        closest = min(findLeaf(root->left), findLeaf(root->right));
        return true;
    }
    if(findClosest(root->left, key, closest)){
        closest = min(closest, findLeaf(root->right));
        return true;
    }
    if(findClosest(root->right, key, closest)){
        closest = min(closest, findLeaf(root->left));
        return true;
    }
    return false;
}
int main(){
    // Let us construct the BST shown in the above figure
    struct Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    int closest = MAX;
    bool b = findClosest(root, k, closest);
    cout << "Distace of the closest key from " << k << " is "
         << closest << endl;
    k = 'C';
    closest = MAX;
    b = findClosest(root, k, closest);
    cout << "Distace of the closest key from " << k << " is "
         << closest << endl;
    k = 'E';
    closest = MAX;
    b = findClosest(root, k, closest);
    cout << "Distace of the closest key from " << k << " is "
         << closest << endl;
    k = 'B';
    closest = MAX;
    b = findClosest(root, k, closest);
    cout << "Distace of the closest key from " << k << " is "
         << closest << endl;
    
    return 0;
}