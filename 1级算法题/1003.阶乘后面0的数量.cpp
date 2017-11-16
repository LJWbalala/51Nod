// n的阶乘后面有多少个0？
// 6的阶乘 = 1*2*3*4*5*6 = 720，720后面有1个0。
// Input
// 一个数N(1 <= N <= 10^9)
// Output
// 输出0的数量
// Input示例
// 5
// Output示例
// 1
// 思路：算数基本定理
// 有0，分解为2*5，寻找2*5的对数，2的因子个数大于5，转化为寻找因子5的个数。又有算数基本定理：
// n！在素数因子分解中p的幂为[n/p]+[n/p2]+[n/p3]+...
// 同时最大次数不会超过logpn。通过换底公式，有ln(n)/ln(p)
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int num=5,sum=0,index=(int)(log(n*1.0)/log(5*1.0));
    for(int i=1; i<=index; ++i) {
        sum+=n/num;
        num*=5;
    }
    cout<<sum<<endl;
    return 0;
}
