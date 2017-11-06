/*
基准时间限制：1 秒 空间限制：131072 KB 分值: 20 难度：3级算法题 收藏  关注
X轴上有N个点，求X轴上一点使它到这N个点的距离之和最小，输出这个最小的距离之和。
Input
第1行：点的数量N。(2 <= N <= 10000)
第2 - N + 1行：点的位置。（-10^9 <= P[i] <= 10^9)
Output
输出最小距离之和
Input示例
5
-1
-3
0
7
9
Output示例
20
*/
#include <bits/stdc++.h>
using namespace std;
long long ans[10005];
int main() {
	int n;
	long long sum=0;
	long long num;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i) {
		cin>>ans[i];
	}
	sort(ans,ans+n);
	if(n%2) num=ans[n/2];
	else num=(ans[n/2]-ans[n/2-1])/2;
	for(int i=0;i<n;++i) sum+=abs(num-ans[i]);
	cout<<sum<<endl;
	return 0;
}
