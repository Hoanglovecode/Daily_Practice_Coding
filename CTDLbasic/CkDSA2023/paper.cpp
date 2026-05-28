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
//inorder
void inorder(node root){
    if(root){
        inorder(root->l);
        cout<<root->data<<' ';
        inorder(root->r);
    }
}
void insert(node &root,int x){
    if(root==nullptr){
        root=createnode(x);
        return;
    }
    if(x<root->data)insert(root->l,x);
    else insert(root->r,x);
}
int findmin(node root){
    while(root->l){
        root=root->l;
    }
    return root->data;
}
int findmax(node root){
    while(root->r){
        root=root->r;
    }
    return root->data;
}
node deletenode(node root,int x){
    if(root==nullptr)return nullptr;
    if(x<root->data){
        root->l=deletenode(root->l,x);
    }
    else if(x>root->data){
        root->r=deletenode(root->r,x);
    }
    else{
        if(!root->l&&!root->r){
            delete root;
            return nullptr;
        }
        else if(root->l==nullptr){
            node tmp=root->r;
            delete root;
            return tmp;
        }
        else if(root->r==nullptr){
            node tmp=root->l;
            delete root;
            return tmp;
        }
        else{
            node tmp=root->r;
            while(root->l){
                tmp=tmp->l;
            }
            root->data=tmp->data;
            root->r=deletenode(root->r,tmp->data);
        }
    }
    return root;
}
int main(){   
}