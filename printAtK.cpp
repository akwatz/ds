#include <iostream>
using namespace std;
 
// A binary Tree node
struct node{
    int data;
    struct node *left, *right;
};
//Function to create new node
node *newnode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
//Function to print nodes at k distance from root
void printDown(node* root, int k){
    if(!root)
        return;
    if(k == 0){
        cout<<root->data<<"\t";
        return;
    }
    printDown(root->left, k - 1);
    printDown(root->right, k - 1);
}
//Function to print nodes at k distance from target node
bool printkdistanceNode(node* root, node* target, int &k, bool &found){
    if(!root)
        return false;
    if(target == root){
        found = true;
        printDown(root, k);
        k--;
        return true;
    }
    bool lbool = printkdistanceNode(root->left, target, k, found);
    bool rbool = printkdistanceNode(root->right, target, k, found);
    if(!lbool && !rbool)
        return false;
    if(found){
        if(k>0 && lbool)
            printDown(root->right, k - 1);
        if(k>0 && rbool)
            printDown(root->left, k - 1);
        if(k == 0){
            cout<<root->data<<"\t";
            k--;
            return true;
        }
        k--;
        return true;
    }
    return false;
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    bool found = false;
    int k = 2;
    printkdistanceNode(root, target, k, found);
    return 0;
}