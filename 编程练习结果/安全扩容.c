/* ex_3_grow_array.c —— 练习 3 骨架：安全扩容
 *
 * 要求
 *   1. 函数签名：int *grow(int *a, int old_n, int new_n)
 *   2. 把 a 从 old_n 个元素扩到 new_n 个（new_n > old_n），**原有数据必须保留**；
 *   3. 新增的位置全部填 0；
 *   4. 必须用临时指针接 realloc 的返回值，判空后才赋回 a（台账 E8 的升级版）；
 *   5. 失败时返回 NULL，并且**原来的内存必须仍然有效**——调用者要能 free 它；
 *   6. a == NULL 或 new_n <= old_n 时返回 NULL。
 *
 * 验收标准
 *   填完 TODO 后运行，输出必须是：
 *       after grow: 1 2 3 0 0 0
 *       grow(bad args) -> NULL
 */
#include <stdio.h>
#include <stdlib.h>

int *grow(int *a, int old_n, int new_n)
{
    if(a==NULL || old_n>new_n) 	return NULL;
    int *p;
    p=realloc(a,new_n);
    if(p==NULL) return NULL;
    int i;
    for (i=0;i<old_n;i++){
    	p[i]=a[i];
	}
	for(  ;i<new_n;i++){
		p[i]=0;
	}
    
    return p;
}

int main(void)
{
    int *a = malloc(3 * sizeof(int));
    int *g;
    int i;

    if (a == NULL)
        return 1;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    g = grow(a, 3, 6);
    if (g == NULL) {
        printf("grow failed -> original block still valid, freeing it\n");
        free(a);
        return 1;
    }

    a = g;
    printf("after grow:");
    for (i = 0; i < 6; i++)
        printf(" %d", a[i]);
    printf("\n");

    free(a);
    a = NULL;

    printf("grow(bad args) -> %s\n", grow(NULL, 3, 6) == NULL ? "NULL" : "not NULL");

    return 0;
}
