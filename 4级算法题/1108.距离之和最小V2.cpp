/*1108 距离之和最小 V2
基准时间限制：1 秒 空间限制：131072 KB 分值: 40 难度：4级算法题 收藏  关注
三维空间上有N个点, 求一个点使它到这N个点的曼哈顿距离之和最小，输出这个最小的距离之和。
点(x1,y1,z1)到(x2,y2,z2)的曼哈顿距离就是|x1-x2| + |y1-y2| + |z1-z2|。即3维坐标差的绝对值之和。
Input
第1行：点的数量N。(2 <= N <= 10000)
第2 - N + 1行：每行3个整数，中间用空格分隔，表示点的位置。（-10^9 <= X[i], Y[i], Z[i] <= 10^9)
Output
输出最小曼哈顿距离之和。
Input示例
4
1 1 1
-1 -1 -1
2 2 2
-2 -2 -2
Output示例
18*/
/*
思路：
中位数性质：给定一个数列，中位数有这样的性质 ：所有数与中位数的绝对差之和最小
（转）证明：首先，给定一个从小到大的数列x1,x2,……，xn,设x是从x1到xn与其绝对差之和最小的数，则显然x位于x1与xn之间。那么，由于x1，xn与它们之间的任意一点的距离之和都相等，且都等于xn-x1，因此接下来可以不考虑x1与xn，而考虑剩下的从x2到x[n-1]的数，同样显然有x必然位于x2和x[n-1]之间，依次类推，最后得出的结论是x就是该数列中间的那个数，或者是中间的那两个数之一，而这个数就是中位数。
 */
#include <bits/stdc++.h>
using namespace std;
int x[10001],y[10001],z[10001];
int zws[3];
int cal(int a[], int n) {
	double num;
	sort(a,a+n);
	num=n%2==0?(a[n/2-1]+a[n/2])/2:a[n/2];
	return num;
}
int main() {
	int n;
	long long dist=0;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i) {
		cin>>x[i]>>y[i]>>z[i];
	}
	int xx=cal(x,n);
	int yy=cal(y,n);
	int zz=cal(z,n);
	for(int i=0;i<n;++i) {
		dist+=abs(x[i]-xx);
		dist+=abs(y[i]-yy);
		dist+=abs(z[i]-zz);
	}
	cout<<dist<<endl;
	return 0;
}