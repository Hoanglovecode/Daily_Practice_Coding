//FIFO
//push
//pop
//front
#include <bits/stdc++.h>
#include <queue>
using namespace std;
//Liệt kê các số nhị phân từ 1 tới N
vector<string>res;
void init(){
   queue<string>q;
   q.push("1");
   res.push_back("1");
   while(res.size()<1000){
      string top=q.front();
      q.pop();
      res.push_back(top+"0");
      res.push_back(top+"1");
      q.push(top+"0");
      q.push(top+"1");
   }
}
int main(){
   init();
   int n;cin>>n;
   for(int i=0;i<n;i++){
      cout<<res[i]<<' ';
   }
}