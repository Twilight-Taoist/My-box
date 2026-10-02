/* ex_3_pack_rgb565.c -- 编程题 C4-3 的填空骨架：手工掩码打包 RGB565
 *
 * 只填 TODO；函数名与参数约定不要改（参考答案 sol_3 用的是同一套）。
 * 编译要求：零警告。
 *
 * 颜色按 5 + 6 + 5 = 16 位打包（这是很多老显卡/位图格式的做法）：
 *     位 15..11 = r（5 位）    位 10..5 = g（6 位）    位 4..0 = b（5 位）
 * 约定：超出范围的输入**不做裁剪**，只取低 5/6/5 位（和硬件的行为一致）。
 *
 * 验收标准：
 *   pack_31_63_31 = 65535
 *   pack_0_0_0 = 0
 *   pack_31_0_0 = 63488
 *   pack_0_63_0 = 2016
 *   unpack_63488_r = 31
 *   unpack_63488_g = 0
 *   roundtrip_rgb = 31 63 31
 *
 * 提示：打包就是"把每一段移到它的位置上再按位或"：
 *       (r << 11) | (g << 5) | b —— 前提是每一段都已经在自己的位宽内。
 *       解包是"先右移到位、再用掩码切出来"。
 */
#include <stdio.h>

struct pack{
	unsigned a:5;
	unsigned b:6;
	unsigned c:5;
	};

/* TODO: 把 r/g/b 打包成一个 16 位的值。 */
unsigned pack_rgb565(unsigned r, unsigned g, unsigned b)
{
	struct pack p565;
	p565.a=r;
	p565.b=g;
	p565.c=b; 
	
    unsigned i=0;
    i|=(p565.a<<11);
    i|=(p565.b<<5);
    i|=(p565.c<<0);
    return i;
}

/* TODO: 拆开一个打包值，结果写进三个输出参数。 */
void unpack_rgb565(unsigned v, unsigned *r, unsigned *g, unsigned *b)
{   
    *r=((v>>11)&0x1fu);
    *g = ((v>>5)&0x3fu);
    *b = (v&0x1fu);
}

int main(void)
{
    unsigned r, g, b;

    printf("pack_31_63_31 = %u\n", pack_rgb565(31u, 63u, 31u));
    printf("pack_0_0_0 = %u\n", pack_rgb565(0u, 0u, 0u));
    printf("pack_31_0_0 = %u\n", pack_rgb565(31u, 0u, 0u));
    printf("pack_0_63_0 = %u\n", pack_rgb565(0u, 63u, 0u));
    printf("pack_0_0_31 = %u\n", pack_rgb565(0u, 0u, 31u));

    unpack_rgb565(pack_rgb565(31u, 63u, 31u), &r, &g, &b);
    printf("roundtrip_r = %u\n", r);
    printf("roundtrip_g = %u\n", g);
    printf("roundtrip_b = %u\n", b);

    unpack_rgb565(pack_rgb565(31u, 0u, 0u), &r, &g, &b);
    printf("unpack_63488_r = %u\n", r);
    printf("unpack_63488_g = %u\n", g);
    printf("unpack_63488_b = %u\n", b);

    /* 超范围只取低位：40 -> 40 & 31 = 8，70 -> 70 & 63 = 6 */
    unpack_rgb565(pack_rgb565(40u, 70u, 40u), &r, &g, &b);
    printf("masked_r = %u\n", r);
    printf("masked_g = %u\n", g);
    printf("masked_b = %u\n", b);
    return 0;
}
