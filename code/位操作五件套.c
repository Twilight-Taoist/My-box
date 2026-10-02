/* ex_1_bit_ops.c -- 编程题 C4-1 的填空骨架：位操作五件套
 *
 * 只填 TODO；函数名与参数约定不要改（参考答案 sol_1 用的是同一套）。
 * 编译要求：零警告。
 *
 * 验收标准（跑起来之后自己对照）：
 *   set_bit3_of_0    = 8
 *   clear_bit3_of_15 = 7
 *   toggle_bit0_of_1 = 0
 *   test_bit3_of_8   = 1
 *   count_bits_0xF0  = 4
 *   count_bits_max   = 32
 *
 * 提示：置位用 |=，清位用 &= ~，翻转用 ^=，测位要写成 (x & mask) != 0；
 *       数 1 的个数可以用"x = x & (x - 1)"每轮干掉最低位的 1。
 */
#include <stdio.h>
#include <limits.h>

/* TODO: 把 x 的第 n 位置成 1。 */
unsigned set_bit(unsigned x, int n)
{
    x|=(1u<<n);
    return x;
}

/* TODO: 把 x 的第 n 位清成 0。 */
unsigned clear_bit(unsigned x, int n)
{
    x&=~(1u<<n);
    return x;
}

/* TODO: 把 x 的第 n 位翻转。 */
unsigned toggle_bit(unsigned x, int n)
{
    x^=(1u<<n);
    return x;
}

/* TODO: x 的第 n 位是 1 就返回 1，否则返回 0。 */
int test_bit(unsigned x, int n)
{
	unsigned mask=(1u<<n);
    
	if((x&mask)!=0){
    	return 1;
	}
    return 0;
}

/* TODO: 返回 x 里 1 的个数（用 x & (x - 1) 的写法，别用除法）。 */
int count_bits(unsigned x)
{
    int cnt=0;
  
    while(x!=0){
     x=x&(x-1);
     cnt++;
	}
    
    return cnt;
}

int main(void)
{
    printf("set_bit3_of_0 = %u\n", set_bit(0u, 3));
    printf("clear_bit3_of_15 = %u\n", clear_bit(15u, 3));
    printf("toggle_bit0_of_1 = %u\n", toggle_bit(1u, 0));
    printf("test_bit3_of_8 = %d\n", test_bit(8u, 3));
    printf("test_bit3_of_7 = %d\n", test_bit(7u, 3));
    printf("count_bits_0xF0 = %d\n", count_bits(0xF0u));
    printf("count_bits_max = %d\n", count_bits(~0u));
    printf("count_bits_0 = %d\n", count_bits(0u));
    return 0;
}
