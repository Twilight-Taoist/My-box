/* ex_1_sum_dynamic.c —— 练习 1 骨架：动态数组求和
 *
 * 要求
 *   1. 用 malloc 在**堆**上分配一个能放 n 个 int 的数组（n 由参数传入）；
 *   2. 把 data[0..n-1] 复制进去；
 *   3. 求和并返回；
 *   4. 函数返回前必须 free，并且 free 之后把指针置 NULL；
 *   5. malloc 失败时返回 -1（而不是崩）。
 *
 * 验收标准
 *   填完 TODO 后运行，输出必须是：
 *       sum = 150
 *       heap array sum(-1 case) = -1
 */
#include <stdio.h>
#include <stdlib.h>

int sum_dynamic(const int *data, int n)
{
   const int *p=malloc(sizeof(int)*n);
    if(p==NULL){
    	return -1;
	}
    int i=0;
    int sum=0;
    for (p=data;i<n;i++){
    	sum+=p[i];
	}
    
    return sum;
}

int main(void)
{
    const int data[5] = {10, 20, 30, 40, 50};

    printf("sum = %d\n", sum_dynamic(data, 5));
    printf("heap array sum(-1 case) = %d\n", sum_dynamic(data, -1));

    return 0;
}
