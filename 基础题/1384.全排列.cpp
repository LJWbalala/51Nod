// 给出一个字符串S（可能有重复的字符），按照字典序从小到大，输出S包括的字符组成的所有排列。例如：S = "1312"，
// 输出为：
//
// 1123
// 1132
// 1213
// 1231
// 1312
// 1321
// 2113
// 2131
// 2311
// 3112
// 3121
// 3211
// Input
// 输入一个字符串S（S的长度 <= 9，且只包括0 - 9的阿拉伯数字）
// Output
// 输出S所包含的字符组成的所有排列
// Input示例
// 1312
// Output示例
// 1123
// 1132
// 1213
// 1231
// 1312
// 1321
// 2113
// 2131
// 2311
// 3112
// 3121
// 3211
#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin>>s;
    int len=s.length();
    int a[len];
    for(int i=0; i<len; ++i) a[i]=s[i]-'0';
    sort(a,a+len);
    do {
        for(int i=0; i<len; ++i) cout<<a[i];
        cout<<endl;
    } while(next_permutation(a,a+len));
    return 0;
}
