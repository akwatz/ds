#include <iostream>
#include <stack>
using namespace std;
//defining the node
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
//Function to print the Inorder traversal of the tree
void printInOrder(node* root){
    stack <node*> s;
    node* current = root;
    while(true){
        if(current){
            s.push(current);
            current = current->left;
        }
        else if(!s.empty()){
            current = s.top();
            s.pop();
            cout<<current->data<<"\t";
            current = current->right;
        }
        else 
            break;
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
    printInOrder(root);
    return 0;
}