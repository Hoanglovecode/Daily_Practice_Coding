//Câu 2 ( 4 điểm) Cho tập X = {a, b, c, d, e ,f }.
//a) Tìm hoán vị tiếp theo của hoán vị S = afedcb. bằng phương pháp sinh
#include <bits/stdc++.h>
using namespace std;
bool nextpermutation(string &s){
    int n=s.length();
    int i=n-2;
    while(i>=0 && s[i]>=s[i+1]) i--;
    if(i<0)return false;
    else{
        int j=n-1;
        while(s[j]<s[i]) j--;
        swap(s[j],s[i]);
        int l=i+1,r=n-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;r--;
        }
    }
    return true;
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   string s="CDBFEA";
   if(nextpermutation(s)) cout<<"Hoan vi ke tiep :"<<s<<endl;
   else cout<<"Da dat den cau hinh cuoi cung"<<endl;
}








// #include <bits/stdc++.h>
// using namespace std;
// bool nextPermutation(string &s)
// {
//     int n = s.length();
//     int i = n - 2;
//     while (i >= 0 && s[i] >= s[i + 1])
//     {
//         i--;
//     }
//     if (i < 0)
//         return false;
//     int j = n - 1;
//     while (s[j] <= s[i])
//     {
//         j--;
//     }
//     swap(s[i], s[j]);
//     reverse(s.begin() + i + 1, s.end());
//     return true;
// }
// int main()
// {
//     string s = "afedcb";
//     if (nextPermutation(s))
//     {
//         cout << "Hoan vi ke tiep: " << s << endl;
//     }
//     else
//     {
//         cout << "Khong co hoan vi ke tiep. Day la hoan vi cuoi cung.\n";
//     }
//     return 0;
// }
