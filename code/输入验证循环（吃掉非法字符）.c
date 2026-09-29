/* ex_2_validate_input.c —— 练习 2 骨架：输入验证循环（吃掉非法字符）
 *
 * 要求
 *   1. count_digits(const char *s)：数出一个字符串里有多少个数字字符，
 *      返回 int。用 kb_getchar() 读，读到 EOF 结束；
 *   2. read_all_digits(int *buf, int max)：从"内存键盘"里连续读整数，
 *      每读到一个就存进 buf（最多 max 个），返回实际存了几个；
 *      不是数字的字符要跳过，但读到一个整数的结尾之后要能把读停下来的
 *      那个字符"塞回去"（提示：kb_pos--），别把它丢了；
 *   3. 循环条件要用短路写法表达 "先看还有没有输入，再看是不是数字"。
 *
 * 验收标准（填完 TODO 后运行，输出必须逐字一致）
 *   s1 = "a1b22c333"
 *   digits in s1 = 6
 *   numbers in s1 = 3
 *   buf[0] = 1, buf[1] = 22, buf[2] = 333
 *   s2 = "
 *
 *     7"
 *   digits in s2 = 1
 *   numbers in s2 = 1
 *   buf[0] = 7
 *   s3 = ""
 *   digits in s3 = 0
 *   numbers in s3 = 0
 *   s4 = "12 34 56 78 90"
 *   digits in s4 = 10
 *   numbers in s4 = 5
 *   buf[0] = 12, buf[1] = 34, buf[2] = 56, buf[3] = 78, buf[4] = 90
 *
 * 想一想：为什么"吃掉非法字符"的循环写成
 *         while ((c = getchar()) != '\n' && c != EOF);
 *         而不是
 *         while ((c = getchar()) != '\n' || c != EOF);
 *         把 || 换上去会发生什么？
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

static int is_digit(int ch)
{
    return ch >= '0' && ch <= '9';
}

int count_digits(const char *s)
{
    int n = 0;

    use_input(s);

    int ch;
    while ((ch=kb_getchar())!=EOF){
    	if(is_digit(ch)){
    		n++;
		}
	}

    return n;
}

int read_all_digits(int *buf, int max)
{
    int n = 0;
    int ch;
    int value=0;
    int digits=0;
    
    while((ch=kb_getchar())!=EOF){
    	if(is_digit(ch)){
    		value=value*10+(ch-'0');
    		digits=1;
		}else {
		    if(digits){
		    	if(n>max){
		    		kb_pos--;
		    		break;
				}
				buf[n++]=value;
			    value=0;
			    digits=0;
			}
			
		}
	}
	
	 if (digits && n < max) {
        buf[n++] = value;
    }

//    需要自己声明局部变量：int ch; int value; int digits;
 //   (void)buf;
 //   (void)max;

    return n;
}

int main(void)
{
    const char *cases[4];
    int i;
    int buf[8];
    int n;
    int k;

    cases[0] = "a1b22c333";
    cases[1] = "\n\n  7";
    cases[2] = "";
    cases[3] = "12 34 56 78 90";

    for (i = 0; i < 4; i++) {
        printf("s%d = \"%s\"\n", i + 1, cases[i]);
        printf("digits in s%d = %d\n", i + 1, count_digits(cases[i]));

        for (k = 0; k < 8; k++)
            buf[k] = -1;

        use_input(cases[i]);
        n = read_all_digits(buf, 8);
        printf("numbers in s%d = %d\n", i + 1, n);

        if (n > 0) {
            printf("buf[0] = %d", buf[0]);
            for (k = 1; k < n; k++)
                printf(", buf[%d] = %d", k, buf[k]);
            printf("\n");
        }
    }

    return 0;
}
