// 有N条鱼每条鱼的位置及大小均不同，他们沿着X轴游动，有的向左，有的向右。游动的速度
// 是一样的，两条鱼相遇大鱼会吃掉小鱼。从左到右给出每条鱼的大小和游动的方向
// （0表示向左，1表示向右）。问足够长的时间之后，能剩下多少条鱼？
// Input
// 第1行：1个数N，表示鱼的数量(1 <= N <= 100000)。
// 第2 - N + 1行：每行两个数A[i], B[i]，中间用空格分隔，分别表示鱼的大小及游动的方向(1 <= A[i] <= 10^9，B[i] = 0 或 1，0表示向左，1表示向右）。
// Output
// 输出1个数，表示最终剩下的鱼的数量。
// Input示例
// 5
// 4 0
// 3 1
// 2 0
// 1 0
// 5 0
// Output示例
// 2
// 用栈来模拟，O(n)即可
// 朝右的小鱼进栈，朝左的小鱼来攻关，看能攻几关，栈里的小鱼就GG几条，如果攻不过去，只能自己GG
#include <bits/stdc++.h>
using namespace std;
int n,dir,size,temp;
stack<int> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n; temp=n;
    for(int i=1; i<=n; ++i) {
        cin>>size>>dir;
        if(dir) s.push(size);
        else {
            while(!s.empty()) {
                if(size>s.top()) {
                    s.pop();
                    temp--;
                } else {
                    temp--;
                    break;
                }
            }
        }
    }
    cout<<temp<<endl;
    return 0;
}
