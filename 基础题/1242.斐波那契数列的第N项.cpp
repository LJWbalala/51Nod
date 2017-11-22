/*
   1242 斐波那契数列的第N项
   基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
   斐波那契数列的定义如下：

   F(0) = 0
   F(1) = 1
   F(n) = F(n - 1) + F(n - 2) (n >= 2)

   (1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, ...)
   给出n，求F(n)，由于结果很大，输出F(n) % 1000000009的结果即可。
   Input
   输入1个数n(1 <= n <= 10^18)。
   Output
   输出F(n) % 1000000009的结果。
   Input示例
   11
   Output示例
   89
   思路：矩阵快速幂 二进制分解
 */
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000000009;
struct mat {
    ll a[2][2];
    mat() {
        a[0][1]=a[1][0]=1;
        a[1][1]=a[0][0]=0;
    }
};
mat qpow(mat& x, mat& y) {
    mat z;
    z.a[0][1]=z.a[1][0]=0;
    for(int i=0; i<=1; ++i) {
        for(int j=0; j<=1; ++j) {
            for(int k=0; k<=1; ++k) {
                z.a[i][j]=(z.a[i][j]%mod+(x.a[i][k]%mod*y.a[k][j])%mod)%mod;
            }
        }
    }
    return z;
}
ll slove(ll n) {
    mat x,res;
    res.a[0][1]=res.a[1][0]=0;
    res.a[1][1]=res.a[0][0]=1;
    x.a[0][0]=1;
    while(n) {
        if(n&1) res=qpow(res,x); //二进制分解
        x=qpow(x,x);
        n>>=1;
    }
    return res.a[0][1];
}
int main() {
    ll n;
    cin>>n;
    cout<<slove(n)<<endl;
    return 0;
}
