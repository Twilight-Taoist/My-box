/* ex_1_menu_loop.c —— 练习 1 骨架：菜单程序 + 输入验证
 *
 * 要求
 *   1. run_menu() 循环显示主菜单，用 kb_getchar() 取一个字符，
 *      然后调用 skip_rest_of_line() 把这一行剩下的字符（包括换行符）全部吞掉；
 *   2. 'A'/'a' 走 handled_a()，'B'/'b' 走 handled_b()，
 *      'Q'/'q' 打印 "bye! bye" 并退出循环，其它任何字符打印 "invalid: X" 重新显示菜单；
 *   3. 大小写都要接受（自己决定用什么写法最清楚）；
 *   4. ch == EOF 时必须跳出循环，不能死循环。
 *
 * 验收标准（填完 TODO 后运行，输出必须逐字一致）
 *   --- handler test ---
 *   you chose A -> alpha
 *   you chose B -> beta
 *   --- run 1 ---
 *   input: "A\nb\nQ\n"
 *   [menu] A) alpha  B) beta  Q) quit
 *   choose> you chose A -> alpha
 *   [menu] A) alpha  B) beta  Q) quit
 *   choose> you chose B -> beta
 *   [menu] A) alpha  B) beta  Q) quit
 *   choose> bye! bye
 *   --- run 2 ---
 *   input: "xyz\nA\nQ\n"
 *   [menu] A) alpha  B) beta  Q) quit
 *   choose> invalid: x
 *   [menu] A) alpha  B) beta  Q) quit
 *   choose> you chose A -> alpha
 *   [menu] A) alpha  B) beta  Q) quit
 *   choose> bye! bye
 *
 * 注意 run 2 里 invalid 只出现"一次"：第一轮读出 'x'，剩下的 "yz\n" 被
 * skip_rest_of_line() 一次吞掉，所以 y、z 不会各自再当一次按键。
 * 如果把 skip_rest_of_line() 去掉，会连续打出三行 invalid（x、y、z）。
 *
 * 想一想：为什么读菜单按键后必须"吞掉这一行剩下的东西"？
 *        不吞会怎样？（提示：下一次 kb_getchar 会读到什么？）
 */
#include <stdio.h>

static const char *kb_buf = "";
static unsigned kb_pos = 0;

static int kb_getchar(void)
{
    if (kb_buf[kb_pos] == '\0')
        return EOF;
    return (int)(unsigned char)kb_buf[kb_pos++];
}

static void use_input(const char *s)
{
    kb_buf = s;
    kb_pos = 0;
}

/* 把当前这一行剩下的字符全部吃掉，包括结尾的换行符 */
static void skip_rest_of_line(void)
{
    int ch;
	while ((ch=kb_getchar())!='\n'&&ch!=EOF); 
     
}

static void handled_a(void)
{
    printf("you chose A -> alpha\n");
}

static void handled_b(void)
{
    printf("you chose B -> beta\n");
}

static void run_menu(void)
{
    int ch;
    int quit = 0;

    while (!quit) {
        printf("[menu] A) alpha  B) beta  Q) quit\n");
        printf("choose> ");

        ch = kb_getchar();

        if (ch == EOF) {                /* 没有输入可读了：结束，绝不死循环 */
            printf("eof\n");
            break;
        }

        switch (ch) {
            case 'A': case 'a': handled_a(); break;
            case 'B': case 'b': handled_b(); break;
            case 'Q': case 'q': printf("bye! bye\n"); quit = 1; break;
           default:            printf("invalid: %c\n", (unsigned char)ch); break;
            printf("TODO\n");
            quit = 1;
            break;
        }

        skip_rest_of_line();            /* 关键：换行符 / 多余字符全部吞掉 */
    }
}

int main(void)
{
    /* 先单独确认两个处理函数本身是对的 */
    printf("--- handler test ---\n");
    handled_a();
    handled_b();

    printf("--- run 1 ---\n");
    printf("input: \"A\\nb\\nQ\\n\"\n");
    use_input("A\nb\nQ\n");
    run_menu();

    printf("--- run 2 ---\n");
    printf("input: \"xyz\\nA\\nQ\\n\"\n");
    use_input("xyz\nA\nQ\n");
    run_menu();

    return 0;
}
