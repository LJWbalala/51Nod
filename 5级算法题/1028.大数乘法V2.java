/*
基准时间限制：2 秒 空间限制：131072 KB 分值: 80 难度：5级算法题 收藏  关注
给出2个大整数A,B，计算A*B的结果。
Input
第1行：大数A
第2行：大数B
(A,B的长度 <= 100000，A,B >= 0）
Output
输出A * B
Input示例
123456
234567
Output示例
28958703552
*/
import java.util.*;
import java.math.*;
public class main{ 
    public static void main(String[] args) { 
        Scanner input = new Scanner(System.in);
        BigInteger a,b;
        a = input.nextBigInteger();
        b = input.nextBigInteger();
        System.out.println(a.multiply(b));
    }
}