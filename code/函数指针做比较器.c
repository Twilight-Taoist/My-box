/* ex_x5_cmp.c —— 第 3 轮 X5 填空骨架：用函数指针做比较器（台账 E7）
 *
 * 只填两个函数体（TODO），main 与验收输出都给你写好了。
 * 填完在 Dev-C++ 里按 F11 运行（`ex_` 前缀在 build.ps1 里只编译不运行）。
 *
 * 要交的东西：
 *   1. int *find_best(const int *a, int n, int (*better)(int, int))
 *      —— `better(x, y)` 返回**非 0** 表示 x 比 y 更优；返回最优元素的**地址**；
 *         n <= 0 或 a == NULL 时返回 NULL。
 *   2. int cmp_max(int x, int y)   —— x 更大时返回非 0
 *   3. int cmp_min(int x, int y)   —— x 更小时返回非 0
 *
 * 验收标准 —— 填对之后应该看到：
 *     max = 41, index = 1
 *     min = 2, index = 5
 *     empty -> NULL (correct)
 *
 * 关键点（也是台账 E7 的靶心）：**"怎么比"变成了运行时可换的数据**——
 * 同一个 find_best，传 cmp_max 就找最大，传 cmp_min 就找最小。
 * 参考答案在 sol_x5_cmp.c，**先自己填**。
 */
#include <stdio.h>

static int cmp_max(int x, int y) { return x > y; }
static int cmp_min(int x, int y) { return x < y; }

static int *find_best(const int *a, int n, int (*better)(int, int))
{
    const int *p;
    const int *best;

    if (a==NULL||n<=0) return 0;/* TODO ① 参数检查：a == NULL 或 n <= 0 → 返回 NULL */
    best=a;
	for( p=a+1;p<a+n;p++){
		if (better(*best,*p)){
			best=p;
		}
	}  /* TODO ② best 从第一个元素开始，从第二个开始逐个用 better(*p, *best) 比较 */
    /* TODO ③ 返回 best（注意返回类型是 int *，不是 const int *，这里要强转） */

//    (void)a; (void)n; (void)better; (void)p; (void)best;
    return (int*)best;
}

int main(void)
{
    const int a[6] = { 3, 41, 7, 19, 41, 2 };
    int *m;

    m = find_best(a, 6, cmp_max);
    if (m == NULL) printf("max -> NULL (not implemented yet)\n");
    else           printf("max = %d, index = %d\n", *m, (int)(m - a));

    m = find_best(a, 6, cmp_min);
    if (m == NULL) printf("min -> NULL (not implemented yet)\n");
    else           printf("min = %d, index = %d\n", *m, (int)(m - a));

    printf("empty -> %s\n", find_best(a, 0, cmp_max) == NULL ? "NULL (correct)" : "not NULL (wrong)");

    return 0;
}
