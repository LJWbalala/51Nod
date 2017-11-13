/*
给出一个长度为N的无序数组，数组中的元素为整数，有正有负包括0，并互不相等。
从中找出所有和 = 0的3个数的组合。如果没有这样的组合，输出No Solution。
如果有多个，按照3个数中最小的数从小到大排序，如果最小的数相等则按照第二小的数排序。
Input
第1行，1个数N，N为数组的长度(0 <= N <= 1000)
第2 - N + 1行：A[i]（-10^9 <= A[i] <= 10^9)
Output
如果没有符合条件的组合，输出No Solution。
如果有多个，按照3个数中最小的数从小到大排序，如果最小的数相等则继续按照第二小的数排序。
每行3个数，中间用空格分隔，并且这3个数按照从小到大的顺序排列。
Input示例
7
-3
-2
-1
0
1
2
3
Output示例
-3 0 3
-3 1 2
-2 -1 3
-2 0 2
-1 0 1
思路：set暴力+优化
 */
/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> s,t;
set<int>::iterator it,jt,kt;
int main() {
    ios::sync_with_stdio(false);
    int n,data,sum=0;
    cin>>n;
    for(int i=1;i<=n;++i) {
        cin>>data;
        s.insert(data);
    }
    int flag=0;
    for(it=s.begin();it!=s.end();++it) {
        sum=0;
        sum-=*it;
        t=s;
        jt=t.find(*it);
        jt++;
        for(;jt!=t.end();++jt) {
            data=sum-*jt;
            kt=t.find(data);
            if(kt!=t.end()&&(*kt!=*jt)&&(*kt>*jt)) {
                cout<<*it<<" "<<*jt<<" "<<*kt<<endl;
                flag=1;
                t.erase(*kt);
            }
        }
    }
    if(!flag) cout<<"No Solution"<<endl;
    return 0;
}*/
/*#include <iostream>
#include <set>
using namespace std;
set<int> s;
set<int>::iterator it,jt,kt;
int main() {
    ios::sync_with_stdio(false);
    int n,data;
    cin>>n;
    for(int i=1;i<=n;++i) {
        cin>>data;
        s.insert(data);
    }
    int flag=0;
    for(it=s.begin();it!=s.end();++it) {
        if(*it>=0) break;
        jt=it;
        jt++;
        kt=prev(s.end());
        while(*jt<*kt) {
            if(*it+*jt+*kt<0) {
                jt++;
            } else if(*it+*jt+*kt>0) {
                kt--;
            } else {
                cout<<*it<<" "<<*jt<<" "<<*kt<<endl;
                flag=1;
                jt++;
                kt--;
            }
        }
    }
    if(!flag) cout<<"No Solution"<<endl;
    return 0;
}*/
#include <iostream>
#include <algorithm>
using namespace std;
int ans[1005];
int main() {
    ios::sync_with_stdio(false);
    int n,flag=0;
    cin>>n;
    for(int i=0;i<n;++i) cin>>ans[i];
    sort(ans,ans+n);
    for(int i=0;i<n;++i) {
        if(ans[i]>=0) break;
        int j=i+1,k=n-1;
        while(ans[j]<ans[k]) {
            if(ans[i]+ans[j]+ans[k]<0) j++;
            else if(ans[i]+ans[j]+ans[k]>0) k--;
            else {
                cout<<ans[i]<<" "<<ans[j]<<" "<<ans[k]<<endl;
                flag=1;
                j++;
                k--;
            }
        }
    }
    if(!flag) cout<<"No Solution"<<endl;
    return 0;
}