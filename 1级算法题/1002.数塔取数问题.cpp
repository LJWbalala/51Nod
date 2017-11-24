// 一个高度为N的由正整数组成的三角形，从上走到下，求经过的数字和的最大值。
// 每次只能走到下一层相邻的数上，例如从第3层的6向下走，只能走到第4层的2或9上。
//
//    5
//   8 4
//  3 6 9
// 7 2 9 5
//
// 例子中的最优方案是：5 + 8 + 6 + 9 = 28
// Input
// 第1行：N，N为数塔的高度。(2 <= N <= 500)
// 第2 - N + 1行：每行包括1层数塔的数字，第2行1个数，第3行2个数......第k+1行k个数。数与数之间用空格分隔（0 <= A[i] <= 10^5) 。
// Output
// 输出最大值
// Input示例
// 4
// 5
// 8 4
// 3 6 9
// 7 2 9 5
// Output示例
// 28
// dp基础题，自底向上处理
#include <iostream>
#include <stdio.h>
using namespace std;
int dp[500][500];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            scanf("%d",&dp[i][j]);
        }
    }
    for(int i=n-1; i>=1; --i) {
        for(int j=1; j<=i; ++j) {
            dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n", dp[1][1]);
    return 0;
}
