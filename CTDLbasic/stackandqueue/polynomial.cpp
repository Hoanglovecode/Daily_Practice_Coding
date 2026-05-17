#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
struct Stack{
    Node *top=nullptr;
};
typedef struct Node * node;
void push(Stack &st,int x){
    node tmp=new Node;
    tmp->data=x;
    tmp->next=st.top;
    st.top=tmp;
}
void pop(Stack &st){
    if(st.top==nullptr)return;
    node tmp=st.top;
    st.top=st.top->next;
    delete tmp;
}
int top(Stack st){
    return st.top->data;
}
bool empty(Stack st){
    return st.top==nullptr;
}
int cal(int a,int b,char op){
    if(op=='+')return a+b;
    if(op=='-')return a-b;
    if(op=='*')return a*b;
    if(op=='/')return a/b;
    return 0;
}
//Tính biểu thức hậu tố
int evaluate(string s){
    Stack st;
    for(int i=0;i<s.length();i++){
        if(s[i]==' ')continue;
        if(isdigit(s[i])){
            int num=0;
            while(i<s.length()&&isdigit(s[i])){
                num=num*10 +(s[i]-'0');
                i++;
            }
            i--;
            push(st,num);
        }
        else{
            int a=top(st);
            pop(st);
            int b=top(st);
            pop(st);
            int result=cal(b,a,s[i]);
            push(st,result);
        }
    }
    return top(st);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    cout<<evaluate(s);
    return 0;
}