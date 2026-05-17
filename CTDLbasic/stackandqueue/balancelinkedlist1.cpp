#include <bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node*next;
};
struct Stack{
    Node *top=nullptr;
};
typedef struct Node* node;
void push(Stack &st,char x){
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
char top(Stack st){
    return st.top->data;
}
bool empty(Stack st){
    return st.top==nullptr;
}
bool isvalid(string s){
    Stack st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(st,s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(empty(st))return false;
            else if(top(st)=='('&&s[i]==')'||
                    top(st)=='{'&&s[i]=='}'||
                    top(st)=='['&&s[i]==']'
            ){
                pop(st);
            }
            else{
                return false;
            }
        }
    }
    return empty(st);
}
int main(){
    string s;
    getline(cin,s);
    if(isvalid(s)){
        cout<<"Cân bằng";
    }
    else cout<<"Biểu thức không cân bằng";
    return 0;
}