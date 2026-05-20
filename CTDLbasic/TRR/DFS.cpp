#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[1000];
bool visited[1000];
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);//vì đây là độ thì vô hướng nên t cần phải dùng 2 chiều
    }
    memset(visited,false,sizeof(visited));//cho toàn bộ mảng visited=false
}
void dfs(int u){
    cout<<u<<' ';
    //Đánh dấu u đã được thăm
    visited[u]=true;
    for(int v:adj[u]){
        //Nếu v chưa được thăm
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   inp();
   dfs(1);
}
//input
//9 đỉnh 9 cạnh
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9