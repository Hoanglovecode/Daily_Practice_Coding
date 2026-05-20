#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,m;
vector<int>adj[1000];
bool visited[1000];
void inp(){
   cin>>n>>m;
   for(int i=0;i<m;i++){
      int x,y;cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   memset(visited,false,sizeof(visited));
}
void bfs(int u){
   queue<int>q;
   q.push(u);
   visited[u]=true;
   while(!q.empty()){
      int v=q.front();
      q.pop();
      cout<<v<<' ';
      for(int x:adj[v]){
         if(!visited[x]){
            q.push(x);
            visited[x]=true;
         }
      }
   }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   inp();
   bfs(1);
}