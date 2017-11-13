/*
1029 大数除法
基准时间限制：4 秒 空间限制：131072 KB 分值: 160 难度：6级算法题 收藏  关注
给出2个大整数A,B，计算A / B和A Mod B的结果。
Input
第1行：大数A
第2行：大数B
(A,B的长度 <= 100000，A,B >= 0）
Output
第1行：A / B
第2行：A Mod B (A % B)
Input示例
987654321
1234
Output示例
800368
209
 */
import java.util.*;
import java.math.*;
public class main{ 
    public static void main(String[] args) { 
        Scanner input = new Scanner(System.in);
        BigInteger a,b;
        a = input.nextBigInteger();
        b = input.nextBigInteger();
        System.out.println(a.divide(b));
        System.out.println(a.remainder(b));
    }
}