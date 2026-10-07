/* ex_1_reverse_string.c —— 练习 1 骨架：原地反转字符串 + 判断回文
 *
 * 要求
 *   1. reverse_str(char *s)：原地反转（不许新建数组），只能用指针走；
 *   2. is_palindrome(const char *s)：是回文返回 1，否则返回 0；
 *   3. 两个函数都必须能安全处理空字符串 ""（这是最容易越界的地方）。
 *
 * 验收标准
 *   填完 TODO 后运行，sol_1_reverse_string.c 的输出就是标准答案。
 *
 * 想一想：如果写成 char *right = s + strlen(s) - 1;，空字符串时 right 指向哪？
 */
#include <stdio.h>
#include <string.h>

void reverse_str(char *s)
{
	int n=strlen(s)-1;
    char *p1=s;
    char *p2=s+n;
    char i;
    char j;
    while (p1<p2){
    	i=*p1;
    	j=*p2;
    	*p1=j;
    	*p2=i;
    	p1++;
    	p2--;
	}
}

int is_palindrome(const char *s)
{
    int n =strlen(s)-1;
    const char *p1=s;
    const char *p2=s+n;
    int i=1;
    if (n<=0) i=0;
    while (p1<p2){
    	if (*p1!=*p2){
    		i=0;
		}
		p1++;
		p2--;
	}
    
    return i;
}

int main(void)
{
    char a[16] = "hello";
    char b[16] = "C";
    char c[16] = "";
    char d[16] = "abba";
    char e[16] = "abc";

    reverse_str(a);
    printf("\"hello\" -> \"%s\"\n", a);
    reverse_str(b);
    printf("\"C\"     -> \"%s\"\n", b);
    reverse_str(c);
    printf("\"\"      -> \"%s\"\n", c);

    printf("is_palindrome(\"abba\") = %d\n", is_palindrome(d));
    printf("is_palindrome(\"abc\")  = %d\n", is_palindrome(e));
    printf("is_palindrome(\"\")     = %d\n", is_palindrome(c));

    return 0;
}
