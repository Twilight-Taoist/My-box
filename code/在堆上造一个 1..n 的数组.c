/* ex_2_make_range.c —— 练习 2 骨架：在堆上造一个 1..n 的数组
 *
 * 要求
 *   1. 函数签名：int *make_range(int n)
 *   2. n <= 0 时返回 NULL（不许 malloc(0) 或 malloc(负数)）；
 *   3. 成功时返回堆上数组的地址，内容依次是 1, 2, ..., n；
 *   4. malloc 失败时返回 NULL；
 *   5. **所有权在调用者**：函数里不许 free，free 由 main 负责。
 *
 * 验收标准
 *   填完 TODO 后运行，输出必须是：
 *       range(5) = 1 2 3 4 5
 *       range(0) -> NULL
 *       range(-3) -> NULL
 *
 * 想一想：为什么这个函数不能返回「局部数组」的地址？（对照第 10 章 C3-3）
 */
#include <stdio.h>
#include <stdlib.h>

int *make_range(int n)
{
	if(n<=0) return NULL;
	int *p=malloc(sizeof(int)*n);
	if(p==NULL) return NULL;
	int i;
	for(i=0;i<n;i++){
		p[i]=i+1;
	}
    
    return p;
}

int main(void)
{
    int *r = make_range(5);
    int i;

    if (r == NULL) {
        printf("range(5) = NULL\n");
    }
    else {
        printf("range(5) =");
        for (i = 0; i < 5; i++)
            printf(" %d", r[i]);
        printf("\n");
        free(r);
        r = NULL;
    }

    printf("range(0) -> %s\n", make_range(0) == NULL ? "NULL" : "not NULL");
    printf("range(-3) -> %s\n", make_range(-3) == NULL ? "NULL" : "not NULL");

    return 0;
}
