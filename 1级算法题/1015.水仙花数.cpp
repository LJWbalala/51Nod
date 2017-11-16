// 水仙花数是指一个 n 位数 ( n >= 3 )，它的每个位上的数字的 n 次幂之和等于它本身。（例如：1^3 + 5^3 + 3^3 = 153）
// 给出一个整数M，求 >= M的最小的水仙花数。
// Input
// 一个整数M（10 <= M <= 1000）
// Output
// 输出>= M的最小的水仙花数
// Input示例
// 99
// Output示例
// 153
// 思路：先打表求出水仙花数，之后遍历数组得出
// 打表程序：
// #include <bits/stdc++.h>
// using namespace std;
// bool pan(int num) {
//     int len;
//     if(num<1000) len=3;
//     else len=4;
//     int temp=num,sum=0;
//     for(int i=0; i<len; ++i) {
//         int r=temp%10;
//         temp/=10;
//         sum+=pow(r,len);
//     }
//     if(sum==num) return true;
//     return false;
// }
// int main() {
//     int num=100;
//     for(;; num++) {
//         if(pan(num)) {
//             cout<<num<<endl;
//             if(num>1000) break;
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int ans[]={153,370,371,407,1634};
int main() {
    int n;
    cin>>n;
    for(int i=0;; ++i) {
        if(ans[i]>=n) {
            cout<<ans[i]<<endl;
            break;
        }
    }
    return 0;
}
