#include <bits/stdc++.h>
#include <queue>
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
        root=createnode(x);
        return;
    }
    if(x<root->data)insert(root->l,x);
    else insert(root->r,x);
}
int findmin(node root){
    while(root->l)
        root=root->l;
    return root->data;
}
int findmax(node root){
    while(root->r)
        root=root->r;
    return root->data;
}
//delete node have value x
node deleteNode(node root,int k){
    if(root==nullptr)return nullptr;
    if(k<root->data){
        root->l=deleteNode(root->l,k);
    }
    else if(k>root->data){
        root->r=deleteNode(root->r,k);
    }
    else{
        if(root->l==nullptr&&root->r==nullptr){
            delete root;
            return nullptr;
        }
        else if(root->l==nullptr){
            node tmp=root->r;
            delete root;
            return tmp;
        }
        else if(root->r=nullptr){
            node tmp=root->l;
            delete root;
            return tmp;
        }
        else{
            node tmp=root->r;
            while(tmp->l){
                tmp=tmp->l;
            }
            root->data=tmp->data;
            root->r=deleteNode(root->r,tmp->data);
        }
    }
    return root;
}
//print current root
void printArrayTree(node root){
    if(root==nullptr)return;
    queue<node>q;
    q.push(root);
    cout<<"[";
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        cout<<cur->data;
        if(!q.empty()||cur->l||cur->r)cout<<",";
        if(cur->l)q.push(cur->l);
        if(cur->r)q.push(cur->r);
    }
    cout<<"]";
}
//print inorder root
void inorder(node root){
    if(root){
        inorder(root->l);
        cout<<root->data<<' ';
        inorder(root->r);
    }
}
int main(){
   int a[]={46,90,60,70,23,40,61,80};
   node root=nullptr;
   for(int x:a)insert(root,x);
   printArrayTree(root);
   cout<<"\nMin value="<<findmin(root);
   cout<<"\nMax value="<<findmax(root);
   int x;
   cout<<"\nWhich node value you want to delete?"<<endl;
   cout<<"Value:";
   cin>>x;
   root=deleteNode(root,x);
   cout<<"Tree currently:";
   printArrayTree(root);
   cout<<"\nInorder Tree:";inorder(root);
   return 0;
}