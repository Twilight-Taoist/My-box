/* ex_1_size_table.c —— 练习 1 骨架：打印"本机类型尺寸表"
 *
 * 要求
 *   1. 补全 print_row()：把类型名左对齐 14 列、字节数右对齐 6 列、
 *      位数右对齐 6 列，打印成一行（位数 = 字节数 * 8）；
 *   2. main 已经给好了表头和数据行，你只要让 9 行数据真的打出来；
 *   3. 不许硬编码字节数！必须用 sizeof 现算——这是本章的核心考点。
 *
 * 提示：格式串写成 "%-14s%6u%6u\n"，宽度写死在格式串里。
 * 验收：填完后运行，输出必须是（逐字一致）
 *     type           bytes  bits
 *     char               1     8
 *     short              2    16
 *     int                4    32
 *     long               4    32
 *     long long          8    64
 *     float              4    32
 *     double             8    64
 *     long double       16   128
 *     void *             8    64
 *
 * 注意：这张表是**本机实测**结果，别背"long 一定是 8 字节"——Windows 的
 *       64 位 gcc 用的是 LLP64 模型，long 只有 4 字节。
 */
#include <stdio.h>

void print_row(const char *name, unsigned int bytes)
{
    unsigned int bits = bytes * 8;

    printf("%-14s%6u%6u\n",name,(unsigned)bytes,(unsigned)bits);
}

int main(void)
{
    printf("%-14s%6s%6s\n", "type", "bytes", "bits");

    print_row("char",        (unsigned)sizeof(char));
    print_row("short",       (unsigned)sizeof(short));
    print_row("int",         (unsigned)sizeof(int));
    print_row("long",        (unsigned)sizeof(long));
    print_row("long long",   (unsigned)sizeof(long long));
    print_row("float",       (unsigned)sizeof(float));
    print_row("double",      (unsigned)sizeof(double));
    print_row("long double", (unsigned)sizeof(long double));
    print_row("void *",      (unsigned)sizeof(void *));

    return 0;
}
