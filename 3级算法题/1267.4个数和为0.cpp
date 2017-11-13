/*
给出N个整数，你来判断一下是否能够选出4个数，他们的和为0，可以则输出"Yes"，否则输出"No"。
Input
第1行，1个数N，N为数组的长度(4 <= N <= 1000)
第2 - N + 1行：A[i]（-10^9 <= A[i] <= 10^9)
Output
如果可以选出4个数，使得他们的和为0，则输出"Yes"，否则输出"No"。
Input示例
5
-1
1
-5
2
4
Output示例
Yes
思路：
二分
第一次是枚举前两个数，后面两个数二分
第二次做法是，先统计出两个不同数的和的数组，然后直接二分
*/
/*#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans[1005];
int main() {
    ios::sync_with_stdio(false);
    int n,flag=0;
    cin>>n;
    for(int i=0;i<n;++i) cin>>ans[i];
    sort(ans,ans+n);
    for(int i=0;i<n;++i) {
        if(ans[i]>=0) break;
        for(int j=i+1;j<n;++j) {
            int l=j+1,r=n-1;
            while(j<r) {
                ll temp=ans[i]+ans[j]+ans[l]+ans[r];
                if(temp>0) r--;
                else if(temp<0) l++;
                else {
                    flag=1;
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    if(!flag) cout<<"No"<<endl;
    return 0;
}*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct node {
    ll sum,x,y;
    node() {sum=x=y=0;}
};
node bns[1000005];
ll ans[1005];
bool cmp(const node &a, const node &b) {
    if(a.sum<b.sum) return true;
    if(a.sum>b.sum) return false;
    if(a.x<b.x) return true;
    if(a.x>b.x) return false;
    if(a.y<=b.y) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    int n,ins=0;
    cin>>n;
    for(int i=0;i<n;++i) cin>>ans[i];
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            bns[ins].sum=ans[i]+ans[j];
            bns[ins].x=ans[i];
            bns[ins].y=ans[j];
            ins++;
        }
    }
    sort(bns,bns+ins,cmp);
    int l=0,r=ins-1,flag=0;
    while(l<r) {
        ll temp=bns[l].sum+bns[r].sum;
        if(temp<0) l++;
        else if(temp>0) r--;
        else {
            if(bns[l].x!=bns[r].x&&bns[l].y!=bns[r].x&&bns[l].y!=bns[r].y) {
                cout<<"Yes"<<endl;
                flag=1;
                return 0;
            }
            l++;
            r--;
        }
    }
    if(!flag) cout<<"No"<<endl;
    return 0;
}