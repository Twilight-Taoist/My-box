/* ex_2_print_binary.c -- 编程题 C4-2 的填空骨架：把一个字节按二进制打印出来
 *
 * 只填 TODO；函数名与参数约定不要改（参考答案 sol_2 用的是同一套）。
 * 编译要求：零警告。
 *
 * 验收标准：
 *   binary_of_00 = 00000000
 *   binary_of_01 = 00000001
 *   binary_of_A5 = 10100101
 *   binary_of_FF = 11111111
 *
 * 提示：从最高位开始，用 (x >> k) & 1u 逐位取值，
 *       不要用"取模再除 2"——那是十进制思维。
 *       八位、高位在前、每一位都必须是 '0' 或 '1'（不能用空格凑）。
 */
#include <stdio.h>

/* TODO: 把 x 的低 8 位按"高位在前"打印成 8 个字符，不要换行。 */
void print_binary8(unsigned char x)
{
    int n=7;
    while (n>=0)  {
    	unsigned mask=(1<<n);
    	printf("%d",(x&mask)!=0);
    	n--;
	}
}

int main(void)
{
    unsigned char vals[4] = { 0x00u, 0x01u, 0xA5u, 0xFFu };
    int i;

    for (i = 0; i < 4; i++) {
        printf("binary_of_%02X = ", vals[i]);
        print_binary8(vals[i]);
        printf("\n");
    }
    return 0;
}
