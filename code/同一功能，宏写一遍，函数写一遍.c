/* ex_1_macro_vs_func.c —— 练习 1 骨架：同一功能，宏写一遍，函数写一遍
 *
 * 要求
 *   1. 补全三个"宏版本"：SQR_M(x)、ABS_M(x)、MAX2_M(a, b)
 *      —— 每个参数都要单独加括号，整个表达式外面还要再加一层括号；
 *   2. 补全三个"函数版本"：sqr_f / abs_f / max2_f，写成 static 函数
 *      （C11 起"函数式宏"的正经替代品就是 static inline 函数）；
 *   3. 不允许用额外的库函数。
 *
 * 验收标准
 *   填完 TODO 后运行，sol_1_macro_vs_func.c 的输出就是标准答案。
 *   重点看最后两行：同一个 i++ 传给宏和传给函数，i 的最终值不一样。
 */
#include <stdio.h>

#define SQR_M(x)       ((x)*(x))    /* TODO: 这里必须是表达式，别用分号结尾 */
#define ABS_M(x)       ((x)<0 ? -(x):(x) )        /* TODO: 提示 ((x) < 0 ? -(x) : (x)) */
#define MAX2_M(a, b)   (((a)>(b))?(a):(b))       /* TODO: 提示 (((a) > (b)) ? (a) : (b)) */

/* 宏体里参数出现两次 —— 副作用就会发生两次（这是宏无法回避的性质） */
#define ADD_TWICE(v, x) do { (v) += (x); (v) += (x); } while (0)

static int sqr_f(int x)
{
    return x*x;
}

static int abs_f(int x)
{
    int i;
    if (x<0){
    	i=-x;
	}else {
		i=x;
	}
    return i;
}

static int max2_f(int a, int b)
{   
    return a>b?a:b;
}

static void add_twice_f(int *v, int x)
{
    *v+=x;
    *v+=x;
}

int main(void)
{
    int i;
    int sum = 0;

    printf("SQR_M(1 + 2)  = %d\n", SQR_M(1 + 2));
    printf("ABS_M(-3 + 1) = %d\n", ABS_M(-3 + 1));
    printf("MAX2_M(7, 3)  = %d\n", MAX2_M(7, 3));
    printf("sqr_f(1 + 2)  = %d\n", sqr_f(1 + 2));
    printf("abs_f(-3 + 1) = %d\n", abs_f(-3 + 1));
    printf("max2_f(7, 3)  = %d\n", max2_f(7, 3));

    i = 0;
    sum = 0;
    ADD_TWICE(sum, i++);
    printf("macro    ADD_TWICE(sum, i++): sum = %d, i = %d\n", sum, i);

    i = 0;
    sum = 0;
    add_twice_f(&sum, i++);
    printf("function add_twice_f(&sum, i++): sum = %d, i = %d\n", sum, i);

    return 0;
}
