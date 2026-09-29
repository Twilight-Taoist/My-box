/* ex_2_struct_swap.c —— 练习 2 骨架：交换两个结构体
 *
 * 要求
 *   1. void swap_point(struct point *a, struct point *b)：用指针交换两个结构体，
 *      实现里要利用"结构体可以整体赋值"这一点（不要逐个成员拷）；
 *   2. swap_by_value 是反面例子，已经写好了，别动它，只要看懂它为什么无效；
 *   3. 不允许用 memcpy。
 *
 * 验收标准
 *   填完 TODO 后运行，sol_2_struct_swap.c 的输出就是标准答案。
 *
 * 想一想：为什么 swap_by_value 里明明交换成功了，main 里的 a、b 却纹丝不动？
 */
#include <stdio.h>

struct point {
    int x;
    int y;
};

void swap_point(struct point *a, struct point *b)
{
	struct point p=*a;
    *a=*b;
    *b=p;
}

static void swap_by_value(struct point a, struct point b)
{
    struct point t = a;             /* 这一步整体赋值就够，不用逐个成员拷 */

    a = b;
    b = t;
    printf("  inside swap_by_value: a = (%d, %d), b = (%d, %d)\n",
           a.x, a.y, b.x, b.y);
}

int main(void)
{
    struct point a = {1, 2};
    struct point b = {9, 8};

    printf("before      : a = (%d, %d), b = (%d, %d)\n", a.x, a.y, b.x, b.y);
    swap_by_value(a, b);
    printf("after value : a = (%d, %d), b = (%d, %d)   <- unchanged\n",
           a.x, a.y, b.x, b.y);
    swap_point(&a, &b);
    printf("after ptr   : a = (%d, %d), b = (%d, %d)\n", a.x, a.y, b.x, b.y);

    return 0;
}
