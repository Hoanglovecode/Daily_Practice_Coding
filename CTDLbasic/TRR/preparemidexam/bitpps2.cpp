//Câu 2 (4,0 điểm) Bn là số xâu bit độ dài n.
//Liệt kê số cách sắp xếp số xâu bit để không có 3 bít 1 kề nhau bằng phương pháp sinh

#include <bits/stdc++.h>
using namespace std;
int ok=1,cnt=1;
void init(int a[],int n){
    for(int i=1;i<=n;i++)a[i]=0;
}
void out(int a[],int n){
    cout<<"Cách "<<cnt<<" :";
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<endl;
}
int check(int a[],int n){
    for(int i=1;i<n;i++)if(a[i]==1 && a[i+1]==1 && a[i+2]==1)return 0;
    return 1;
}
void gen(int a[],int n){
    int i=n;
    while(i>=1 && a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=1;
}
void method(int a[],int n){
    init(a,n);
    while(ok){
        if(check(a,n)){
            out(a,n);
            cnt++;
        }
        gen(a,n);
    }
}
int main(){
   int n;cin>>n;
   int a[n+1];
   method(a,n);
}
/*
Gọi bn là chuõi có độ dài n không chứa các bit 1 kề nhau
Để tạo ra một chuỗi độ dài n không chứa các bit 1 kề nhau, có 2 trường hợp:
-	Kí tự cuối cùng là bit 0.
-	Kí tự cuối cùng là bit 1.
Trường hợp 1 thì bit đứng trước đó (n-1) có thể bằng 0 hoặc 1.Như vậy phần còn lại là 1 xâu bit có độ dài n-1 thỏa mãn điều kiện. Số cách B(n-1).
Trường hợp 2 thì bit đứng trước đó bắt buộc bằng 0.Như vậy phần còn lại phía trước là 1 xâu bit có độ dài n-2 thỏa mãn điều kiện. Số cách B(n-2).
Hệ thức truy hồi: Bn = B(n-1) + B(n-2) và n>=3.
# Lời giải: từ hệ thức truy hồi ta có phương trình đặc trưng:
r^2 = r +1
từ phương trình trên ta giải được r = (1+5^(1/2))/2 và r = (1-5^(1/2))/2
ta có Bn = a1*((1+5^(1/2))/2)^n+a2*((1+5^(1/2))/2)^n
với n = 1 thì Bn=2 và với n=2 thì Bn=3
nên ta có a2=  

*/
