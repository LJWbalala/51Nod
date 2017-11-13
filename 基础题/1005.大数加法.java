/*
1005 大数加法
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
给出2个大整数A,B，计算A+B的结果。
Input
第1行：大数A
第2行：大数B
(A,B的长度 <= 10000 需注意：A B有可能为负数）
Output
输出A + B
Input示例
68932147586
468711654886
Output示例
537643802472
 */
import java.util.*;
import java.math.*;
public class main{ 
    public static void main(String[] args) { 
        Scanner input = new Scanner(System.in);
        BigInteger a,b;
        a = input.nextBigInteger();
        b = input.nextBigInteger();
        System.out.println(a.add(b));
    }
}