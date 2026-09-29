/* ex_1_struct_stats.c —— 练习 1 骨架：结构体数组的统计
 *
 * 要求
 *   1. int total(const struct student *a, int n)
 *      —— 返回全班总分；
 *   2. const struct student *best(const struct student *a, int n)
 *      —— 返回分数最高的那个元素的地址（不是分数！）；
 *         有并列最高分时返回第一个；n <= 0 或 a == NULL 时返回 NULL；
 *   3. void print_all(const struct student *a, int n)
 *      —— 打印表头和每一行，格式见 sol_1_struct_stats.c 的输出；
 *   4. 三个函数都必须用 const 指针接参数（你承诺不改学生的内容）。
 *
 * 验收标准
 *   填完 TODO 后运行，sol_1_struct_stats.c 的输出就是标准答案。
 */
#include <stdio.h>

struct student {
    char name[12];
    int score;
};

int total(const struct student *a, int n);

const struct student *best(const struct student *a, int n);

void print_all(const struct student *a, int n);

int main(void)
{
    struct student cls[4] = {
        {"Tom", 82},
        {"Ann", 95},
        {"Bob", 95},
        {"Cy",  61}
    };
    const struct student *b = best(cls, 4);

    print_all(cls, 4);
    printf("total = %d\n", total(cls, 4));
    printf("best  = %s with %d\n", b->name, b->score);

    return 0;
}

int total(const struct student *a, int n)
{
    const struct student *p=a; 
    if(p==NULL||n<=0) return -1;
    
    int i=0;
    int sum=0;
    for( i=0;i<n;i++){
    	sum+=p[i].score;
	}
    
    return sum;
}

const struct student *best(const struct student *a, int n)
{
    struct student *best=(struct student *)&a[0];
    if(a==NULL||n<=0) return NULL;
    int i;
    for(i=1;i<n;i++){
    	if (a[i].score>best->score){
    		best=(struct student *)&(a[i]);
		}
	}
    return best;
}

void print_all(const struct student *a, int n)
{
    if (a == NULL || n <= 0) return;
    printf("%-10s%s\n", "name", "score");
    int i;
    for ( i = 0; i < n; i++) {
        printf("%-11s%d\n", a[i].name, a[i].score);
    }
}
