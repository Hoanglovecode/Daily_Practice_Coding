#include <iostream>
using namespace std;
//b
struct Node{
    int data;
    Node *left, *right;
};
//c
Node* createNode(int x){
    Node* p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

void insert(Node* &root, int x){
    if(root == NULL){
        root = createNode(x);
        return;
    }

    if(x < root->data)
        insert(root->left, x);
    else if(x > root->data)
        insert(root->right, x);
}
//d
int findMin(Node* root){
    while(root->left)
        root = root->left;
    return root->data;
}
//d
int findMax(Node* root){
    while(root->right)
        root = root->right;
    return root->data;
}
//e
Node* deleteNode(Node* root, int k){
    if(root == NULL) return NULL;

    if(k < root->data)
        root->left = deleteNode(root->left, k);

    else if(k > root->data)
        root->right = deleteNode(root->right, k);

    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;

        while(temp->left)
            temp = temp->left;

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
//f
void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    int a[] = {46,90,60,70,23,40,61,80};

    Node* root = NULL;

    for(int x : a)
        insert(root, x);

    cout << "Tang dan: ";
    inorder(root);

    cout << "\nMin = " << findMin(root);
    cout << "\nMax = " << findMax(root);

    root = deleteNode(root, 70);

    cout << "\nSau khi xoa 70: ";
    inorder(root);

    return 0;
}