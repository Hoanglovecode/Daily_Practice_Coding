//Cho 10 viên gồm 3 loại xanh xanh, đỏ và vàng, các viên bi cùng màu không phân biệt
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n=15,a[50];
ll landem=0;
void out(){
    landem++;
    cout<<"Hoan vi thu "<<landem<<" : ";
    for(int i=1;i<=n;i++){
        if(a[i]==1) cout<<"X";
        else if(a[i]==2) cout<<"D";
        else cout<<"V";
    }
    cout<<"\n";
}
void Try(int k){
    for(int i=1;i<=3;i++){
        a[k]=i;
        if(k==n) out();
        else Try(k+1);
    }
}
int main(){
    Try(1);
    cout<<"Tong cach sap xep la : "<<landem;
}
//# minh họa 5 lần đếm cuối cùng.

//Hoán vị thứ 59045 : VVVVVVVVDD
//Hoán vị thứ 59046 : VVVVVVVVDV
//Hoán vị thứ 59047 : VVVVVVVVVX
//Hoán vị thứ 59048 : VVVVVVVVVD
//Hoán vị thứ 59049 : VVVVVVVVVV