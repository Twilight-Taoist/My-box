/* ex_1_divmod.c —— 练习 1 骨架：用指针参数把两个结果带回来
 *
 * 要求
 *   1. int divmod(int a, int b, int *q, int *r)
 *      - b != 0：把商写进 *q、把余数写进 *r，函数返回 0；
 *      - b == 0：不许改动 *q / *r，直接返回 -1。
 *   2. 商和余数直接用 C 的 / 和 % 算（向零截断），不要自己写特判分支。
 *   3. 不许用全局变量，不许让函数打印任何东西。
 *
 * 验收输出（填完 TODO 后应当逐字一致）
 *   divmod(17, 5)   -> 0, q = 3, r = 2
 *   divmod(-17, 5)  -> 0, q = -3, r = -2
 *   divmod(17, -5)  -> 0, q = -3, r = 2
 *   divmod(7, 0)    -> -1, q = -1, r = -1 (untouched)
 *
 * 编译：gcc -std=c11 -Wall -Wextra -o ex_1_divmod.exe ex_1_divmod.c
 */
#include <stdio.h>

int divmod(int a, int b, int *q, int *r)
{
    if ( b==0 ) return -1;
    int i=a/b;
    int j=a%b;
	*q=i;
	*r=j; 
    
    return 0;
}

int main(void)
{
    int q, r, rc;

    q = -1; r = -1;
    rc = divmod(17, 5, &q, &r);
    printf("divmod(17, 5)   -> %d, q = %d, r = %d\n", rc, q, r);

    q = -1; r = -1;
    rc = divmod(-17, 5, &q, &r);
    printf("divmod(-17, 5)  -> %d, q = %d, r = %d\n", rc, q, r);

    q = -1; r = -1;
    rc = divmod(17, -5, &q, &r);
    printf("divmod(17, -5)  -> %d, q = %d, r = %d\n", rc, q, r);

    q = -1; r = -1;
    rc = divmod(7, 0, &q, &r);
    printf("divmod(7, 0)    -> %d, q = %d, r = %d (untouched)\n", rc, q, r);

    return 0;
}
