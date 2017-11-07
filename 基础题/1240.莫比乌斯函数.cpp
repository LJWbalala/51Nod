/*
1240 莫比乌斯函数
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
莫比乌斯函数，由德国数学家和天文学家莫比乌斯提出。梅滕斯(Mertens)首先使用μ(n)（miu(n)）作为莫比乌斯函数的记号。（据说，高斯(Gauss)比莫比乌斯早三十年就曾考虑过这个函数）。
具体定义如下：
如果一个数包含平方因子，那么miu(n) = 0。例如：miu(4), miu(12), miu(18) = 0。
如果一个数不包含平方因子，并且有k个不同的质因子，那么miu(n) = (-1)^k。例如：miu(2), miu(3), miu(30) = -1,miu(1), miu(6), miu(10) = 1。
给出一个数n, 计算miu(n)。
Input
输入包括一个数n，(2 <= n <= 10^9)
Output
输出miu(n)。
Input示例
5
Output示例
-1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mubi(ll n) {
	ll mu=1;
	for(ll i=2;i*i<=n;++i) {
		if(n%i==0) {
			mu*=-1;
			ll k=0;
			do {
				k++;
				if(k>1) {
					mu=0;break;
				}
				n/=i;
			}while(n%i==0);
		} 
	}
	if(n>1) mu*=-1;
	return mu;
}
int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	cout<<mubi(n)<<endl;
	return 0;
}