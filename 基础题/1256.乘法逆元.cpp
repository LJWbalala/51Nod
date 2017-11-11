/*
1256 乘法逆元
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
给出2个数M和N(M < N)，且M与N互质，找出一个数K满足0 < K < N且K * M % N = 1，如果有多个满足条件的，输出最小的。
Input
输入2个数M, N中间用空格分隔（1 <= M < N <= 10^9)
Output
输出一个数K，满足0 < K < N且K * M % N = 1，如果有多个满足条件的，输出最小的。
Input示例
2 3
Output示例
2

思路：
因为N与M互质，gcd(N,M)=1
所以 K*M%N=1 改写为K*M（恒等于）1 即 K*M（恒等于）gcd(M,N)
转化为求exgcd
解出大于0的最小正值即可
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) {
		x=1;y=0;return a;
	}
	ll ans=exgcd(b,a%b,x,y);
	ll temp=x;
	x=y;
	y=temp-a/b*y;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	ll m,n;
	cin>>m>>n;
	ll x,y;
	exgcd(m,n,x,y);
	cout<<((x%n)+n)%n<<endl;
	return 0;
}