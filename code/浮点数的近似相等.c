/* ex_2_nearly_equal.c —— 练习 2 骨架：浮点数的"近似相等"
 *
 * 背景：C2-3 已经实测过，0.1 + 0.2 == 0.3 的结果是假。所以浮点数不能用 == 比较。
 *
 * 要求
 *   1. 补全 nearly_equal(a, b, eps)：两数之差的**绝对值**小于 eps 时返回 1，
 *      否则返回 0；
 *   2. 不许用 fabs()（本资料的编译脚本不带 -lm），自己判断正负把符号处理掉；
 *   3. 只准用四则运算和比较，不准用数学库。
 *
 * 验收：填完后运行，输出必须是（逐字一致）
 *     0.1 + 0.2 == 0.3                  -> 0
 *     nearly_equal(0.3, 0.1+0.2, 1e-9)  -> 1
 *     nearly_equal(0.3, 0.1+0.2, 1e-15) -> 1
 *     nearly_equal(1e9+1, 1e9, 1e-6)    -> 0
 *     nearly_equal(1e9+1, 1e9, 2.0)     -> 1
 */
#include <stdio.h>

int nearly_equal(double a, double b, double eps)
{
    double diff = a - b;

    if (diff<0) diff=-diff;
    if (diff < eps) return 1; 
    return 0;
}

int main(void)
{
    printf("0.1 + 0.2 == 0.3                  -> %d\n", 0.1 + 0.2 == 0.3);
    printf("nearly_equal(0.3, 0.1+0.2, 1e-9)  -> %d\n", nearly_equal(0.3, 0.1 + 0.2, 1e-9));
    printf("nearly_equal(0.3, 0.1+0.2, 1e-15) -> %d\n", nearly_equal(0.3, 0.1 + 0.2, 1e-15));
    printf("nearly_equal(1e9+1, 1e9, 1e-6)    -> %d\n", nearly_equal(1e9 + 1, 1e9, 1e-6));
    printf("nearly_equal(1e9+1, 1e9, 2.0)     -> %d\n", nearly_equal(1e9 + 1, 1e9, 2.0));

    return 0;
}
