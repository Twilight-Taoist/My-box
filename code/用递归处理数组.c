/* ex_2_recursive_array.c —— 练习 2 骨架：用递归处理数组
 *
 * 要求（三个函数体里都不许出现 for / while / do）
 *   1. int sum_rec(const int *a, int n)               —— 前 n 个元素之和
 *   2. int max_rec(const int *a, int n)               —— 前 n 个元素的最大值
 *   3. int count_rec(const int *a, int n, int target) —— target 在前 n 个元素里出现几次
 *
 * 边界约定
 *   n <= 0 时：sum_rec 返回 0，count_rec 返回 0，max_rec 返回 INT_MIN（表示"没有元素"）。
 *
 * 验收输出（填完 TODO 后应当逐字一致）
 *   sum_rec(a, 5)        = 26
 *   sum_rec(a, 0)        = 0
 *   max_rec(a, 5)        = 9
 *   max_rec(a, 0)        = -2147483648
 *   count_rec(a, 5, 9)   = 2
 *   count_rec(a, 5, 100) = 0
 *
 * 编译：gcc -std=c11 -Wall -Wextra -o ex_2_recursive_array.exe ex_2_recursive_array.c
 */
#include <stdio.h>
#include <limits.h>

int sum_rec(const int *a, int n)
{
    if (n<=0){
    	return 0;
	} 
    
    return a[n-1]+sum_rec(a,n-1);
}

int max_rec(const int *a, int n)
{
	int max=0;
	if (n<=0){
		return INT_MIN;
	}
	
	{
		if ( a[n-1]>max_rec(a,n-1)){
			max=a[n-1];
		}else max=max_rec(a,n-1);
	}
    return max;
}

int count_rec(const int *a, int n, int target)
{
    if(n<=0){
    	return 0;
	}
	
	int cnt=0;
	if (a[n-1]==target){
		cnt+=count_rec(a,n-1,target)+1;
	}else {
		cnt+=count_rec(a,n-1,target)+0;
	}
    
    return cnt;
}

int main(void)
{
    int a[5] = {3, 9, 1, 9, 4};

    printf("sum_rec(a, 5)        = %d\n", sum_rec(a, 5));
    printf("sum_rec(a, 0)        = %d\n", sum_rec(a, 0));
    printf("max_rec(a, 5)        = %d\n", max_rec(a, 5));
    printf("max_rec(a, 0)        = %d\n", max_rec(a, 0));
    printf("count_rec(a, 5, 9)   = %d\n", count_rec(a, 5, 9));
    printf("count_rec(a, 5, 100) = %d\n", count_rec(a, 5, 100));

    return 0;
}
