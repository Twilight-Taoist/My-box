/* ex_1_print_receipt.c —— 练习 1 骨架：用字段宽度打印一张对齐的小票
 *
 * 要求
 *   1. 补全 print_row()：名称左对齐 14 列、数量右对齐 5 列、单价和金额
 *      都右对齐 10 列且保留 2 位小数；金额 = 数量 * 单价，现场算；
 *   2. main 里的表头已经给好，最后的分隔行和 TOTAL 行也要你补上
 *      （TOTAL 行只有金额，同样右对齐 10 列、2 位小数）；
 *   3. 不许用一串空格去"凑对齐"，宽度必须写在格式串里。
 *
 * 提示：格式串写成 "%-14s%5d%10.2f%10.2f\n"。
 * 验收：填完后运行，输出必须与讲义 C4-1 的验收输出逐字一致。
 */
#include <stdio.h>

void print_row(const char *name, int qty, double price)
{
    printf("%-14s%5d%10.2f%10.2f\n",name,qty,price,qty*price); 
}

int main(void)
{
    const char *items[3] = {"pen", "notebook", "usb cable"};
    int    qty[3]   = {3, 2, 1};
    double price[3] = {2.50, 12.00, 39.90};
    double total = 0.0;
    int i;

    printf("%-14s%5s%10s%10s\n", "item", "qty", "price", "subtotal");

    for (i = 0; i < 3; i++) {
        print_row(items[i], qty[i], price[i]);
        total += qty[i] * price[i];
    }
    
    printf("%-14s%5s%10s%10s\n", "------", "", "", "------");
    printf("%-14s%5s%10s%10.2f\n", "TOTAL", "", "", total);

    return 0;
}
