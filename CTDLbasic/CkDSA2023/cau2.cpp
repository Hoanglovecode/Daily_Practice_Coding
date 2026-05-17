#include <bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('|| s[i]=='['|| s[i]=='{'){
            st.push(s[i]);
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(st.empty())return false;
            else{
                if( (st.top()=='('&& s[i]==')') ||
                    (st.top()=='{'&& s[i]=='}') ||
                    (st.top()=='['&& s[i]==']')
                )st.pop();
                else return false;
            }
        }
    }
    if(st.empty())return true;
    else return false;
}
int main(){
   string s;
   getline(cin,s);
   if(isvalid(s)){
    cout<<"Cân bằng";
   }
   else{
    cout<<"Biểu thức trên không cân bằng"; 
   }
}
//(3+4*(14-12/(6*4)))