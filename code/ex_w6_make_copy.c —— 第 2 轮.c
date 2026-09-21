/* ex_w6_make_copy.c —— 第 2 轮 W6 填空骨架（台账 E9 / d12）
 *
 * 只填 make_copy 的函数体（4 个 TODO），main 给你写好了。
 * 填完在 Dev-C++ 里按 F11 运行（`ex_` 前缀在 build.ps1 里只编译不运行）。
 *
 * 要交的东西：
 *   int *make_copy(const int *src, int n);
 *   - 返回一份**堆上**副本；src == NULL 或 n <= 0 返回 NULL；
 *   - malloc 失败返回 NULL（不许崩）；所有权交给调用者（函数里不许 free）。
 *
 * 验收标准 —— 填对之后应该看到：
 *     copy[0] = 3, copy[3] = 1
 *     copy == src ? 0
 *     after copy[0]=99: src[0] = 3, copy[0] = 99
 *     make_copy(NULL,4) -> NULL
 *     make_copy(src,0)  -> NULL
 *
 * 参考答案在 sol_w6_make_copy.c，**先自己填**。
 */
#include <stdio.h>
#include <stdlib.h>

static int *make_copy(const int *src, int n)
{
    int *p;
    int i;

    if(src==NULL || n<=0) return 0;/* TODO ① src == NULL 或 n <= 0 时返回 NULL */
    p=malloc(sizeof(int)*n);    /* TODO ② 分配 n 个 int 的堆内存（注意 malloc 的参数是字节数） */
    if (p==NULL) return NULL; /* TODO ③ 分配失败返回 NULL */
    for (i=0;i<n;i++){
	p[i]=src[i];
	}  /* TODO ④ 把 src 的内容逐个写进去（malloc 不清零，不能跳过这一步） */

    /* 填完实现后，这一行可以删掉 */
    return p;
}

int main(void)
{
    const int src[4] = { 3, 1, 4, 1 };
    int *copy = make_copy(src, 4);

    if (copy == NULL) {
        printf("make_copy returned NULL (not implemented yet, or it failed)\n");
        return 1;
    }

    printf("copy[0] = %d, copy[3] = %d\n", copy[0], copy[3]);
    printf("copy == src ? %d\n", copy == src);

    copy[0] = 99;
    printf("after copy[0]=99: src[0] = %d, copy[0] = %d\n", src[0], copy[0]);

    free(copy);
    copy = NULL;

    printf("make_copy(NULL,4) -> %s\n", make_copy(NULL, 4) == NULL ? "NULL" : "not NULL");
    printf("make_copy(src,0)  -> %s\n", make_copy(src, 0) == NULL ? "NULL" : "not NULL");

    return 0;
}
