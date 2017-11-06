/*
一个M*N矩阵中有不同的正整数，经过这个格子，就能获得相应价值的奖励，先从左上走到右下，再从右下走到左上。第1遍时只能向下和向右走，第2遍时只能向上和向左走。两次如果经过同一个格子，则该格子的奖励只计算一次，求能够获得的最大价值。
 
例如：3 * 3的方格。

1 3 3
2 1 3
2 2 1

能够获得的最大价值为：17。1 -> 3 -> 3 -> 3 -> 1 -> 2 -> 2 -> 2 -> 1。其中起点和终点的奖励只计算1次。
Input
第1行：2个数M N，中间用空格分隔，为矩阵的大小。(2 <= M, N <= 200)
第2 - N + 1行：每行M个数，中间用空格隔开，对应格子中奖励的价值。(1 <= A[i,j] <= 10000)
Output
输出能够获得的最大价值。
Input示例
3 3
1 3 3
2 1 3
2 2 1
Output示例
17
*/
/*
思路：双线DP，看成两个人一起从（1,1）到（N，M），走的路径不能相同。
*/
/*方法1：按照路径长度考虑，路径总长度：tot=x+y-1，dp[tot][x1][x2]，两个人的横坐标x1，x2*/
#include <bits/stdc++.h>
using namespace std;
int ans[205][205],dp[405][205][205];
int main() {
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j) 
            scanf("%d",&ans[i][j]);
    memset(dp,0,sizeof(dp));
    for(int tot=1;tot<=N+M-1;++tot)//路径长度
        for(int i=1;i<=N&&(1<=tot+1-i);++i)
            for(int j=1;j<=N&&(1<=tot+1-i);++j) {
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i-1][j-1]);
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i-1][j]);
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i][j-1]);
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i][j])+ans[i][tot+1-i]+ans[j][tot+1-j];
                if(i==j) dp[tot][i][j]-=ans[i][tot+1-i];
            }
    printf("%d\n",dp[N+M-1][N][N]);
    return 0;
}
/*方法2：按照走到走了几步，总的步数：tot=x+y-2*/
#include <bits/stdc++.h>
using namespace std;
int ans[205][205],dp[405][205][205];
int main() {
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j) 
            scanf("%d",&ans[i][j]);
    memset(dp,0,sizeof(dp));
    dp[0][1][1]=ans[1][1];//一步都没走
    for(int tot=1;tot<=N+M-2;++tot)//走了几步
        for(int i=1;i<=N&&(i-1<=tot);++i)
            for(int j=1;j<=N&&(j-1<=tot);++j) {
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i-1][j-1]);
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i-1][j]);
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i][j-1]);
                dp[tot][i][j]=max(dp[tot][i][j],dp[tot-1][i][j])+ans[i][tot+2-i]+ans[j][tot+2-j];
                if(i==j) dp[tot][i][j]-=ans[i][tot+2-i];
            }
    printf("%d\n",dp[N+M-2][N][N]);
    return 0;
}
/*方法3：对方法2的优化，滚动数组*/
#include <stdio.h>
#include <string.h>
int ans[201][201],dp[2][201][201];
int max(int a, int b) {if(a>=b) return a;return b;}
int main() {
    int M,N;
    scanf("%d %d",&M,&N);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j) 
            scanf("%d",&ans[i][j]);
    memset(dp,0,sizeof(dp));
    dp[0][1][1]=ans[1][1];//一步都没走
    int dir=0;
    //tot->走了几步
    for(int tot=1;tot<=N+M-2;++tot) {
        dir=1-dir;
        for(int i=1;i<=N&&(i-1<=tot);++i)
            for(int j=1;j<=N&&(j-1<=tot);++j) {
                dp[dir][i][j]=max(dp[dir][i][j],dp[1-dir][i-1][j-1]);
                dp[dir][i][j]=max(dp[dir][i][j],dp[1-dir][i-1][j]);
                dp[dir][i][j]=max(dp[dir][i][j],dp[1-dir][i][j-1]);
                dp[dir][i][j]=max(dp[dir][i][j],dp[1-dir][i][j])+ans[i][tot+2-i]+ans[j][tot+2-j];
                if(i==j) dp[dir][i][j]-=ans[i][tot+2-i];
            }
    }
    printf("%d\n",dp[dir][N][N]);
    return 0;
}