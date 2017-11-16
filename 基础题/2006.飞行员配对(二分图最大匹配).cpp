// 第二次世界大战时期，英国皇家空军从沦陷国征募了大量外籍飞行员。由皇家空军派出的每一架
// 飞机都需要配备在航行技能和语言上能互相配合的2名飞行员，其中1名是英国飞行员，另1名是
// 外籍飞行员。在众多的飞行员中，每一名外籍飞行员都可以与其他若干名英国飞行员很好地配合
// 。如何选择配对飞行的飞行员才能使一次派出最多的飞机。对于给定的外籍飞行员与英国飞行员
// 的配合情况，试设计一个算法找出最佳飞行员配对方案，使皇家空 军一次能派出最多的飞机 。
// 对于给定的外籍飞行员与英国飞行员的配合情况，编程找出一个最佳飞行员配对方案， 使皇家
// 空军一次能派出最多的飞机。
// Input
// 第1行有2个正整数 m 和 n。n 是皇家空军的飞行 员总数(n<100); m 是外籍飞行员数。外籍
// 飞行员编号为 1 ~m; 英国飞行员编号为 m+1 ~n。接下来每行有 2 个正整数 i 和 j，表示
// 外籍飞行员 i 可以和英国飞行员 j 配合。输入最后以 2 个-1 结束。
// Output
// 第 1 行是最佳飞行 员配对方案一次能派出的最多的飞机数 M。如果所求的最佳飞行员配对方
// 案不存在，则输出‘No Solution !’。
// Input示例
// 5 10
// 1 7
// 1 8
// 2 6
// 2 9
// 2 10
// 3 7
// 3 8
// 4 7
// 4 8
// 5 10
// -1 -1
// Output示例
// 4
#include <iostream>
#include <string.h>
using namespace std;
int g[105][105],vis[105],who[105];
int n,m;
bool find(int x) {
    for(int i=m+1; i<=n; ++i) {
        if(g[x][i]&&!vis[i]) {
            vis[i]=1;
            if(!who[i]||find(who[i])) {
                who[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    memset(g,0,sizeof(g));
    memset(who,0,sizeof(who));
    int u,v,sum;
    cin>>m>>n;
    while(cin>>u>>v) {
        if(u==-1&&v==-1) break;
        g[u][v]=1;
    }
    sum=0;
    for(int i=1; i<=m; ++i) {
        memset(vis,0,sizeof(vis));
        if(find(i)) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
