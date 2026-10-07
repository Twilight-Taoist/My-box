/* ex_2_pow_table.c —— 练习 2 骨架：用循环 + 复合赋值算整数幂
 *
 * 要求
 *   1. 补全 ipow()：返回 base 的 exp 次方；用循环乘法，不许用 pow()；
 *   2. 循环体里用复合赋值（result *= base），体会 x *= y 就是 x = x * y；
 *   3. 返回值类型是 unsigned int，正好用来观察"无符号溢出会回绕"；
 *      exp = 0 时任何数的 0 次方都是 1（循环一次都不进）。
 *
 * 验收：填完后运行，输出必须与讲义 C4-2 的验收输出逐字一致。
 * 附加思考：最后一行的 2^32 为什么不是 4294967296？换成 int 会怎样？
 */
#include <stdio.h>

unsigned int ipow(unsigned int base, int exp)
{
    unsigned int result = 1;
    int  i=0;
	while (i<exp){
		result*=base;
		i++;
	} 

    /* TODO: 用循环把 result 乘上 base，共 exp 次 */
    
    return result;
}

int main(void)
{
    int e;

    for (e = 0; e <= 32; e++)
        printf("2^%2d = %u\n", e, ipow(2u, e));

    return 0;
}
