#include <bits/stdc++.h>
using namespace std;
int ok=1;
char x[]={'A','B','C','D','E','F'};
void init(int a[],int n){
    for(int i=1;i<=n;i++)a[i]=i;
}
void out(int a[],int n){
    for(int i=1;i<=n;i++)cout<<x[a[i]-1];
    cout<<endl;
}
void gen(int a[],int n){
    int i=n-1;
    while(i>=1 && a[i]>a[i+1])i--;
    if(i==0)ok=0;
    else{
        int j=n;
        while(a[i]>a[j])j--;
        swap(a[i],a[j]);
        int l=i+1,r=n;
        while(l<r){
            swap(a[l],a[r]);
            l++;r--;
        }
    }
}
void method(int a[],int n){
    init(a,n);
    while(ok){
        out(a,n);
        gen(a,n);
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;cin>>n;
   int a[n+1];
   method(a,n);
   
}