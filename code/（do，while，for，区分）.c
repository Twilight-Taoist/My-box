/*
 * 文件名：ex_1_three_loop_forms.c
 * 考点：while / for / do-while 三者怎么选、差别在哪；
 *       do-while "至少执行一次"这个特性什么时候是优势
 * 编译：gcc -std=c11 -Wall -Wextra -o ex_1_three_loop_forms.exe ex_1_three_loop_forms.c
 *
 * 说明：这是练习骨架，功能留了 TODO，所以现在只编译不运行（编译必须干净）。
 *       自己补完之后再跑，和 sol_1_three_loop_forms.c 对照。
 *
 * 任务：
 *   ① sum_while(n) 用 while 求和 1+2+...+n；n <= 0 时返回 0
 *   ② sum_for(n)   用 for   求和 1+2+...+n；n <= 0 时返回 0
 *   ③ sum_do_while(n) 用 do-while 求和 1+2+...+n
 *      要求：n <= 0 时返回 0。想清楚 do-while 至少执行一次会带来什么后果，
 *            再决定把 n <= 0 这个判断放在哪里。
 *   ④ 主函数里已经给好了验收调用，不要改验收数据。
 *
 * 验收输出见 review/r04 的 C4-1。
 */

#include <stdio.h>

/* ① 用 while 求和：1 + 2 + ... + n */
int sum_while(int n)
{
    int sum = 0;
    int i=1;

    while ( i<=n ){
    	sum+=i;
    	i++;
	}
       /* 这一行只是让骨架零警告，补完功能后可以删掉 */
    return sum;
}

/* ② 用 for 求和：1 + 2 + ... + n */
int sum_for(int n)
{
    int sum = 0;
    int i;
    for( i=1 ; i<=n ; i++ ){
    	sum+=i;
	} 

    return sum;
}

/* ③ 用 do-while 求和：1 + 2 + ... + n，且 n <= 0 时必须返回 0 */
int sum_do_while(int n)
{
    int sum = 0;
    int i=1;
    if (n<=0) return 0;
    do {
    	sum+=i;
    	i++;
	}while (i<=n);

    return sum;
}

int main(void)
{
    printf("sum_while(5)     = %d\n", sum_while(5));
    printf("sum_for(5)       = %d\n", sum_for(5));
    printf("sum_do_while(5)  = %d\n", sum_do_while(5));
    printf("sum_while(0)     = %d\n", sum_while(0));
    printf("sum_do_while(0)  = %d\n", sum_do_while(0));
    printf("sum_while(-3)    = %d\n", sum_while(-3));
    printf("sum_do_while(-3) = %d\n", sum_do_while(-3));
    return 0;
}
