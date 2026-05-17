#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define NO_EDGE -1
struct Edge{int u,v,weight;};
struct DSU{
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int i){
        if(parent[i]!=i) parent[i]=find(parent[i]);
        return parent[i];
    }
    bool unite(int i,int j){
        int ri=find(i),rj=find(j);
        if(ri==rj) return false;
        if(rank[ri]<rank[rj]) swap(ri,rj);
        parent[rj]=ri;
        if(rank[ri]==rank[rj]) rank[ri]++;
        return true;
    }
};
int main(){
    int n;
    cout<<"Nhap so dinh: ";
    cin>>n;
    if(n<=0){
        cout<<"So dinh khong hop le.\n";
        return 1;
    }
    vector<vector<int>> mst(n,vector<int>(n,NO_EDGE));
    vector<Edge> edges;
    cout<<"Nhap ma tran chieu dai canh ("<<NO_EDGE<<" la khong co canh):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int w;
            cin>>w;
            if(i<j&&w!=NO_EDGE) edges.push_back({i,j,w});
        }
    sort(edges.begin(),edges.end(),[](Edge a,Edge b){return a.weight<b.weight;});
    DSU dsu(n);
    int mstEdgeCount=0;
    long long totalWeight=0;
    for(auto e:edges){
        if(mstEdgeCount==n-1) break;
        if(dsu.unite(e.u,e.v)){
            mst[e.u][e.v]=e.weight;
            mst[e.v][e.u]=e.weight;
            totalWeight+=e.weight;
            mstEdgeCount++;
        }
    }
    if(mstEdgeCount<n-1){
        cout<<"Do thi khong lien thong - MST khong ton tai.\n";
    }else{
        cout<<"Tong trong so MST: "<<totalWeight<<endl;
        cout<<"Ma tran cay khung nho nhat:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout.width(4),cout<<mst[i][j];
            cout<<endl;
        }
    }
    return 0;
}

// #include<iostream>
// #include<algorithm>
// #define MAX 20
// using namespace std;
// int par[MAX],numsOfChild[MAX];
// struct Edge{
//     char u,v;
//     int w;
// };
// Edge dsc[]={
//     {'A','D',5},
//     {'C','E',5},
//     {'D','F',6},
//     {'A','B',7},
//     {'B','E',7},
//     {'B','C',8},
//     {'F','E',8},
//     {'B','D',9},
//     {'E','G',9},
//     {'F','G',11},
//     {'D','E',15}
// };
// int e=11,v=7;
// int getIndex(char c){
//     return c-'A'+1;
// }
// int findpar(int child){
//     if(child==par[child]) return child;
//     return par[child]=findpar(par[child]);
// }
// bool addEdge(int u,int v){
//     int x=findpar(u);
//     int y=findpar(v);
//     if(x==y) return false;
//     if(numsOfChild[x]>numsOfChild[y])
//         swap(x,y);
//     par[x]=y;
//     numsOfChild[y]+=numsOfChild[x];
//     return true;
// }
// void kruskal(){
//     for(int i=1;i<=v;i++){
//         par[i]=i;
//         numsOfChild[i]=1;
//     }
//     sort(dsc,dsc+e,[](Edge a,Edge b){
//         return a.w<b.w;
//     });
//     int sum=0;
//     cout<<"Cay khung nho nhat:\n";
//     for(int i=0;i<e;i++){
//         int u=getIndex(dsc[i].u);
//         int v=getIndex(dsc[i].v);
//         if(addEdge(u,v)){
//             cout<<dsc[i].u<<" "<<dsc[i].v<<" "<<dsc[i].w<<endl;
//             sum+=dsc[i].w;
//         }
//     }
//     cout<<"\nW(T)="<<sum<<endl;
// }
// int main(){
//     kruskal();
// }









// #include<iostream>
// #include<algorithm>
// #define MAX 20
// using namespace std;
// int par[MAX],numsOfChild[MAX];
// int v,e;
// struct canh{
//     int v1,v2,w;
// };
// canh dsc[MAX];
// void input(){
//     cout<<"Nhap so dinh va canh: ";
//     cin>>v>>e;
//     for(int i=1;i<=v;i++){
//         par[i]=i;
//         numsOfChild[i]=1;
//     }
//     for(int i=1;i<=e;i++)
//         cin>>dsc[i].v1>>dsc[i].v2>>dsc[i].w;
// }
// int findpar(int child){
//     if(child==par[child])
//         return child;
//     return par[child]=findpar(par[child]);
// }
// bool addEdge(int v1,int v2){
//     int x=findpar(v1);
//     int y=findpar(v2);
//     if(x==y)
//         return false;
//     if(numsOfChild[x]>numsOfChild[y])
//         swap(x,y);
//     par[x]=y;
//     numsOfChild[y]+=numsOfChild[x];

//     return true;
// }
// void sortEdge(){
//     for(int i=1;i<e;i++){
//         for(int j=i+1;j<=e;j++){
//             if(dsc[i].w>dsc[j].w)
//                 swap(dsc[i],dsc[j]);
//         }
//     }
// }
// void kruskal(int &sum){
//     sortEdge();
//     cout<<"\nDanh sach canh sau khi sap xep:\n";
//     for(int i=1;i<=e;i++)
//         cout<<dsc[i].v1<<" "<<dsc[i].v2<<" "<<dsc[i].w<<endl;
//     cout<<"\nCay khung nho nhat:\n";
//     int cnt=0;
//     for(int i=1;i<=e;i++){
//         if(addEdge(dsc[i].v1,dsc[i].v2)){
//             cout<<dsc[i].v1<<" "<<dsc[i].v2<<" "<<dsc[i].w<<endl;
//             sum+=dsc[i].w;
//             cnt++;
//             if(cnt==v-1)
//                 break;
//         }
//     }
// }
// int main(){
//     input();
//     int sum=0;
//     kruskal(sum);
//     cout<<"\nW(T)="<<sum<<endl;
//     return 0;
// }






