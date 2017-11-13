/*
给出一个整数K和一个无序数组A，A的元素为N个互不相同的整数，找出数组A中所有和等于K的数对。
例如K = 8，数组A：{-1,6,5,3,4,2,9,0,8}，所有和等于8的数对包括(-1,9)，(0,8)，(2,6)，(3,5)。
Input
第1行：用空格隔开的2个数，K N，N为A数组的长度。(2 <= N <= 50000，-10^9 <= K <= 10^9)
第2 - N + 1行：A数组的N个元素。（-10^9 <= A[i] <= 10^9) 
Output
第1 - M行：每行2个数，要求较小的数在前面，并且这M个数对按照较小的数升序排列。
如果不存在任何一组解则输出：No Solution。
Input示例
8 9
-1
6
5
3
4
2
9
0
8
Output示例
-1 9
0 8
2 6
3 5
思路：set查找，找到一对，删除
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
set<ll>::iterator it,ii;
int main() {
    ios::sync_with_stdio(false);
    ll K,N,data;
    cin>>K>>N;
    for(ll i=1;i<=N;++i) {
        cin>>data;
        s.insert(data);
    }
    ll flag=0;
    for(it=s.begin();it!=s.end();it++) {
        ii=s.find(K-*it);
        if(ii!=s.end()&&((*ii+*it)==K)&&(*ii!=*it)) {
            flag=1;
            cout<<*it<<" "<<*ii<<endl;
            s.erase(*ii);
        }
    }
    if(!flag) cout<<"No Solution"<<endl;
    return 0;
}