/*
1284 2 3 5 7的倍数
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个数N，求1至N中，有多少个数不是2 3 5 7的倍数。 例如N = 10，只有1不是2 3 5 7的倍数。
Input
输入1个数N(1 <= N <= 10^18)。
Output
输出不是2 3 5 7的倍数的数共有多少。
Input示例
10
Output示例
1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	/*容斥原理*/
	ll one=n/2+n/3+n/5+n/7;
	ll two=n/(2*3)+n/(2*5)+n/(2*7)+n/(3*5)+n/(3*7)+n/(5*7);
	ll three=n/(2*3*5)+n/(2*3*7)+n/(2*5*7)+n/(3*5*7);
	ll four=n/(2*3*5*7);
	cout<<n-(one-two+three-four)<<endl;
	return 0;
}