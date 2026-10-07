/* ex_2_my_strlen.c —— 练习 2 骨架：手写 my_strlen，并用 sizeof 做对照
 *
 * 要求
 *   1. 补全 my_strlen()：一路数到 '\0' 为止，返回字符个数（不含 '\0'）；
 *   2. 不许调用 <string.h> 里的 strlen（本章还没到第 11 章，先自己数）；
 *   3. main 里的调用已经写好，你只要让函数正确。
 *
 * 验收：填完后运行，输出必须与讲义 C4-2 的验收输出逐字一致。
 * 想一想：为什么同一个 "hello"，sizeof 得到 6 而 my_strlen 得到 5？
 */
#include <stdio.h>

int my_strlen(const char *s)
{
    int i;
    
    for( i=0 ; s[i]!='\0';i++);
    return i;
}

int main(void)
{
    char a[] = "hello";
    char b[10] = "hi";

    printf("my_strlen(\"\")      = %d\n", my_strlen(""));
    printf("my_strlen(\"C\")     = %d\n", my_strlen("C"));
    printf("my_strlen(\"hello\") = %d\n", my_strlen("hello"));
    printf("a: sizeof = %u, my_strlen = %d\n", (unsigned)sizeof(a), my_strlen(a));
    printf("b: sizeof = %u, my_strlen = %d\n", (unsigned)sizeof(b), my_strlen(b));

    return 0;
}
