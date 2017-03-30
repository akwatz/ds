#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
//Definition of the node for the linked list
struct ListNode
{
    int data;
    ListNode* next;    
};
//Definition of the node for the binary tree
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};
//Function to create a new node for the linked list
ListNode* newListNode(int newData){
    ListNode* temp = new ListNode;
    temp->data = newData;
    temp->next = NULL;
    return temp;
}
//Function to create new node for the binary tree
void push(ListNode** head,int newData){
    ListNode* temp = newListNode(newData);
    if(!head)
        *head = temp;
    else{
        temp->next = *head;
        *head = temp;
    }
}
//Function to create a new node for the binary tree
BinaryTreeNode* newBinaryTreeNode(int newData){
    BinaryTreeNode* temp = new BinaryTreeNode;
    temp->data = newData;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//Function to insert node in a binary tree
void insertNodeBinaryTree(BinaryTreeNode* &root,int newData,queue <BinaryTreeNode*> &q){
    BinaryTreeNode* temp = newBinaryTreeNode(newData);
    if(!root){
        root = temp;
        q.push(root);
        return;
    }    
    BinaryTreeNode* front = q.front();
    if(!front->left){
        front->left = temp;
        q.push(temp);
        return;
    }
    if(!front->right){
        front->right = temp;
        q.push(temp);
        q.pop();
        return;
    }
}
//Function to do inorder traversal of the tree
void inorder(BinaryTreeNode* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}
int main()
{
    // create a linked list shown in above diagram
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */
    vector <int> listData;
    BinaryTreeNode *root = NULL;
    while(head){
        listData.push_back(head->data);
        head = head->next;
    }
    queue <BinaryTreeNode*> btConstructor;
    for(int i = 0;i<listData.size();i++)
        insertNodeBinaryTree(root,listData[i],btConstructor);
    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorder(root);
    cout<<endl;
    return 0;
}