//a)Đếm số cách xếp 9 viên bi trên thành hàng ngang để ko có các viên bị cùng màu xếp kề nhau.
#include <bits/stdc++.h>
using namespace std;
int n=9,x[100],cnt[4],dem=0;
void out(){
    for(int i=1;i<=n;i++){
        if(x[i]==1)cout<<"X ";
        else if(x[i]==2)cout<<"D ";
        else cout<<"V ";
    }
    cout<<endl;
}
void Try(int i=1){
    for(int j=1;j<=3;j++){
        if(cnt[j]<3){
            if(i==1 || x[i-1]!=j){
                x[i]=j;
                cnt[j]++;
                if(i==n){
                    out();
                    dem++;
                }
                else Try(i+1);
                cnt[j]--;
            }
        }
    }
}
int main(){
   freopen("output.txt","w",stdout);
   Try(1);
   cout<<"Tổng số cách = "<<dem;
}
/*
Trường hợp 1 (0 lỗi-xen kẽ hoàn toàn):
xdxdxdxd
dxdxdxdx
->có 2 cấu hình=>số cách=2.7C3=70 cách
Trường hợp 2 (1 lỗi-có 1 cặp kề nhau):
3.x-dd-x-d-x
4.x-d-x-dd-x
5.d-xx-d-x-d
6.d-x-d-xx-d
->có 4 cấu hình=>số cách=4.6C2=60 cách
Trường hợp 3 (2 lỗi-có 2 cặp kề nhau):
7.xx-dd-x-d
8.xx-d-x-dd
9.x-dd-xx-d
10.x-d-xx-dd
11.dd-xx-d-x
12.dd-x-d-xx
13.d-xx-dd-x
14.d-x-dd-xx
->có 8 cấu hình=>số cách=8.5C1=40 cách
Trường hợp 4 (3 lỗi-có 3 cặp kề nhau):
15.xx-ddd-x
16.x-ddd-xx
17.dd-xxx-d
18.d-xxx-dd
->có 4 cấu hình=>số cách=4.4C0=4 cách
Trường hợp 5 (4 lỗi-dồn cục):
Sinh ra 0 cách(do có 4 lỗi nhưng chỉ có 3 bi Vàng,không đủ để chèn vách ngăn)
19.xxx-ddd
20.ddd-xxx
*/