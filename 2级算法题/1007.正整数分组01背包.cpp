/*
将一堆正整数分为2组，要求2组的和相差最小。
例如：1 2 3 4 5，将1 2 4分为1组，3 5分为1组，两组和相差1，是所有方案中相差最少的。
Input
第1行：一个数N，N为正整数的数量。
第2 - N+1行，N个正整数。
(N <= 100, 所有正整数的和 <= 10000)
Output
输出这个最小差
Input示例
5
1
2
3
4
5
Output示例
1
思路：
尽可能的均分为sum/2,但是不能用贪心，明显是错的，样例都举不出来
相当于给了一个sum/2的背包，问能够装的最大值，再计算差值
*/
#include <bits/stdc++.h>
using namespace std;
int ans[105],dp[5005];
int main() {
	ios::sync_with_stdio(false);
	int n,sum=0;
	memset(ans,0,sizeof(ans));
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>ans[i];
		sum+=ans[i];
	}
	int temp=sum;
	if(sum%2) sum=sum/2+1;
	else sum=sum/2;
	for(int i=1;i<=n;++i) {
		for(int j=sum;j>=ans[i];--j) {
			dp[j]=max(dp[j],dp[j-ans[i]]+ans[i]);
		}
	}
	cout<<abs(temp-dp[sum]-dp[sum])<<endl;
	return 0;
}