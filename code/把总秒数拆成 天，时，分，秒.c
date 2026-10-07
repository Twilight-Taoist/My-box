/* ex_1_seconds_split.c —— 练习 1 骨架：把总秒数拆成 天/时/分/秒
 *
 * 要求
 *   1. 补全 split_time()：用整数除法 / 和取模 % 拆出天、小时、分钟、秒，
 *      通过指针写回调用者的四个变量；
 *   2. 只用 / 和 %，不许用浮点，不许用循环（一次算完）；
 *   3. 提示：1 天 = 86400 秒，1 小时 = 3600 秒，1 分钟 = 60 秒。
 *
 * 验收：填完后运行，输出必须与讲义 C4-1 的验收输出逐字一致。
 * 想一想：为什么 (total % 86400) / 3600 不能写成 total / 3600？
 */
#include <stdio.h>

void split_time(int total, int *days, int *hours, int *minutes, int *seconds)
{
    int i=0;
	int j=0;
	int k=0;
	
	*days=total/86400;
	i=total%86400;
	*hours=i/3600;
	j=i%3600;
	*minutes=j/60;
	k=j%60;
	*seconds=k;
}

int main(void)
{
    int cases[4] = {500000, 3661, 59, 86400};
    int i, d = 0, h = 0, m = 0, s = 0;

    for (i = 0; i < 4; i++) {
        split_time(cases[i], &d, &h, &m, &s);
        printf("%d seconds = %d d %d h %d min %d s\n", cases[i], d, h, m, s);
    }

    return 0;
}
