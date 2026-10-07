/* ex_2_debug_macro.c —— 练习 2 骨架：一套能开关的调试宏
 *
 * 要求
 *   1. DBG(lv, fmt, ...)：只有当 lv <= DBG_LEVEL 时才打印
 *      —— 必须写成 do { ... } while (0)，这样它才是一条语句；
 *   2. STR(x)：把参数变成字符串（用 # 运算符）；
 *      XSTR(x)：先把参数里的宏展开，再变字符串（两级宏的经典写法）；
 *   3. HERE()：打印"当前文件名 : 行号 : 函数名"，用 __FILE__ / __LINE__ / __func__；
 *   4. CHECK(cond)：把条件本身和结果一起打印出来（用 # 打印条件原文），
 *      失败也只打印，不许 abort、不许 exit；
 *   5. 全部实现完之后，DBG_LEVEL 改成 1，第 2 条日志应该消失。
 *
 * 验收标准
 *   填完 TODO 后运行，sol_2_debug_macro.c 的输出就是标准答案
 *   （HERE 那一行里的行号会不一样，因为文件长度不同，这是正常的）。
 */
#include <stdio.h>

#define DEBUG 1
#define DBG_LEVEL 2

#define STR(x)   #x
#define XSTR(x)  STR(x)

#define HERE()   printf("HERE -> %s:%d in %s\n", __FILE__, __LINE__, __func__)

#define DBG(lv, fmt, ...)                                 \
    do {                                                  \
        if ((lv) <= DBG_LEVEL)                            \
            printf("[L%d] " fmt "\n", (lv), __VA_ARGS__); \
    } while (0)

#define CHECK(cond) \
    printf("CHECK %-14s -> %s\n", #cond, (cond) ? "pass" : "fail")
int main(void)
{
    int x = 42;
    int y = 0;

    printf("STR(1 + 2)     = %s\n", STR(1 + 2));
    printf("STR(x + y)     = %s\n", STR(x + y));
    printf("XSTR(__LINE__) = %s\n", XSTR(__LINE__));

    DBG(1, "start, x = %d", x);
    DBG(2, "y = %d", y);
    DBG(3, "you should NOT see this line: %d", 999);
    printf("DBG(3, ...) was filtered out\n");

    HERE();

    CHECK(x > 0);
    CHECK(y == 99);

#if DEBUG
    printf("DEBUG is on\n");
#endif

    return 0;
}
