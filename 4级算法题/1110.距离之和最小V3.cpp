/*X轴上有N个点，每个点除了包括一个位置数据X[i]，还包括一个权值W[i]。
点P到点P[i]的带权距离 = 实际距离 * P[i]的权值。
求X轴上一点使它到这N个点的带权距离之和最小，输出这个最小的带权距离之和。
Input
第1行：点的数量N。(2 <= N <= 10000)
第2 - N + 1行：每行2个数，中间用空格分隔，分别是点的位置及权值。
（-10^5 <= X[i] <= 10^5，1 <= W[i] <= 10^5)
Output
输出最小的带权距离之和。
Input示例
5
-1 1
-3 1
0 1
7 1
9 1
Output示例
20*/
/*
思路：
x的权重为w，相当于有w个点在x的位置，之后按照中位数处理
统一按照奇数的处理方法过了，但是分类讨论奇数和偶数却有一些例子过不了，郁闷
*/
#include <bits/stdc++.h>
using namespace std;
struct node {
	long long x,w;
}data[10005];
bool cmp(node a, node b) {
	if(a.x<b.x) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	int n,len=0;
	long long num;
	cin>>n;
	long long sum=0;
	for(int i=0;i<n;++i) {
		cin>>data[i].x>>data[i].w;
		len+=data[i].w;
	}
	sort(data,data+n,cmp);
	int temp=len/2+1;
	for(int i=0;i<n;++i) {
		if(temp>data[i].w) temp-=data[i].w;
		else {
			num=data[i].x;
			break;
		}
	}
	/*if(len%2) {
		int temp=len/2+1;
		for(int i=0;i<n;++i) {
			if(temp>data[i].w) temp-=data[i].w;
			else {
				num=data[i].x;
				break;
			}
		}
	} else {
		int temp1=len/2;
		int temp2=len/2+1;
		int flag=0;
		for(int i=0;i<n;++i) {
			if(temp1>data[i].w||flag) temp1-=data[i].w;
			else {
				num=data[i].x;
				flag=1;
			}
			if(temp2>data[i].w) temp2-=data[i].w;
			else {
				num+=data[i].x;
				break;
			}
		}
	}*/
	for(int i=0;i<n;++i) sum+=abs(data[i].x-num)*data[i].w;
	cout<<sum<<endl;
	return 0;
}