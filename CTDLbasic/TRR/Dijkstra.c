#include <stdio.h>
#define N 10
#define INF 1000000000
char ten[N] = {'a','b','c','d','e','g','h','k','m','n'};
int tim(char x){
    for(int i=0;i<N;i++){
        if(ten[i]==x) return i;
    }
    return -1;
}
int chon(int dist[], int visited[]){
    int min=INF;
    int pos=-1;
    for(int i=0;i<N;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            pos=i;
        }
    }
    return pos;
}
void induong(int parent[], int v){
    if(parent[v]==-1){
        printf("%c ", ten[v]);
        return;
    }
    induong(parent,parent[v]);
    printf("%c ", ten[v]);
}
int main(){
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]=INF;
        }
    }
    for(int i=0;i<N;i++){
        a[i][i]=0;
    }
    int A=0,B=1,C=2,D=3,E=4,G=5,H=6,K=7,M=8,Nn=9;
    a[A][B]=1;a[B][A]=1;
    a[A][E]=3;a[E][A]=3;
    a[A][Nn]=2;a[Nn][A]=2;
    a[A][M]=3;a[M][A]=3;
    a[B][E]=1;a[E][B]=1;
    a[B][C]=4;a[C][B]=4;
    a[C][E]=2;a[E][C]=2;
    a[C][G]=2;a[G][C]=2;
    a[C][D]=6;a[D][C]=6;
    a[D][G]=2;a[G][D]=2;
    a[D][H]=2;a[H][D]=2;
    a[D][K]=3;a[K][D]=3;
    a[E][G]=4;a[G][E]=4;
    a[E][M]=5;a[M][E]=5;
    a[G][H]=3;a[H][G]=3;
    a[G][M]=5;a[M][G]=5;
    a[H][K]=1;a[K][H]=1;
    a[M][K]=3;a[K][M]=3;
    a[Nn][M]=6;a[M][Nn]=6;
    char s, t;
    printf("Nhập đỉnh bắt đầu: ");
    scanf(" %c",&s);
    printf("Nhập đỉnh kết thúc: ");
    scanf(" %c",&t);
    int start=tim(s);
    int end=tim(t);
    if(start==-1 || end==-1){
        printf("Nhập sai đỉnh!\n");
        return 0;
    }
    int dist[N], visited[N], parent[N];
    for(int i=0;i<N;i++){
        dist[i]=INF;
        visited[i]=0;
        parent[i]=-1;
    }
    dist[start]=0;
    // Dijkstra
    for(int i=0;i<N-1;i++){
        int u = chon(dist, visited);
        if(u==-1) break;
        visited[u] = 1;
        for(int v=0;v<N;v++){
            if(visited[v]==0 && a[u][v]!=INF){
                if(dist[u]+a[u][v]<dist[v]){
                    dist[v]=dist[u]+a[u][v];
                    parent[v]=u;
                }
            }
        }
    }
    if(dist[end]==INF){
        printf("Không có đường đi\n");
    } else {
        printf("Tổng trọng số: %d\n", dist[end]);
        printf("Đường đi thõa mãn: ");
        induong(parent, end);
    }
    return 0;
}