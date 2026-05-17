#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *l;
    Node *r;
};
typedef struct Node* node;
node createnode(int x){
    node p=new Node;
    p->data=x;
    p->l=nullptr;
    p->r=nullptr;
    return p;
}
void insert(node &root,int x){
    if(root==nullptr){
        root=createNode(x);
        return;
    }
    if(x<root->data)insert(root->l,x);
    else insert(root->r=x);
}
int findmin(node root){
    while(root->l)
        root=root->l;
    return root->data;
}
int findmin(node root){
    while(root->r)
        root=root->r;
    return root->>data;
}
node deleteNode(node root,int k){
    if(root==nullptr)return null;
    if(k<root->data){
        root->l=deleteNode(root->left,k);
    }
    else if(k>)
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
}