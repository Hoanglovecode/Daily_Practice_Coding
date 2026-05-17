//LIFO
#include <bits/stdc++.h>
#include <stack>
using namespace std;
void convertbinary(int n){
    stack<int>st;
   while(n!=0){
    st.push(n%2);
    n/=2;
   }
   while(!st.empty()){
    cout<<st.top();
    st.pop();
   }
}
void reverse(string s){
    stringstream ss(s);
    stack<string>st;
    string token;
    while(ss>>token){
        st.push(token);
    }
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
}
int main(){
    convertbinary(63);
    cout<<endl;
    string s="Lee van hoang";
    reverse(s);
    cout<<endl;
    //Next Greater Element
    cout<<"NHập số lượng phần tử:";
    int n;cin>>n;
    int a[n],b[n];
    for(int &x:a)cin>>x;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty()&& a[st.top()]<a[i]){
                b[st.top()]=a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        b[st.top()]=-1;
        st.pop();
    }
    for(int x:b){
        cout<<x<<" ";
    }

}