/* ex_2_word_count.c -- 编程题 C4-2 的填空骨架：统计行数 / 单词数 / 字符数
 *
 * 只填 TODO；函数名与参数约定不要改（参考答案 sol_2 用的是同一套）。
 * 编译要求：零警告。
 *
 * 验收标准：
 *   count_return = 0
 *   lines = 4    （换行符个数；最后一行没有换行符就不算）
 *   words = 6    （连续的"非空白字符"算一个词）
 *   chars = 29   （读到的字符数，不是文件字节数）
 *   文件打不开时返回非 0，并且把三个计数器都清成 0
 *
 * 提示：fgetc 一次读一个字符，配 <ctype.h> 里的 isspace() 判断空白；
 *       "当前在词里 / 不在词里"需要一个状态变量，这就是全部难点。
 */
#include <stdio.h>
#include <ctype.h>

#define SAMPLE "d13_ex2_sample.txt"

void make_sample(const char *path)
{
    FILE *fp = fopen(path, "w");

    if (fp == NULL) return;
    fputs("one two\nthree\n\nfour five six\n", fp);
    fclose(fp);
}

/* TODO: 实现它。成功返回 0，打不开返回 -1。 */
int count_text(const char *path, long *lines, long *words, long *chars)
{
    FILE *fp=fopen(path,"r");
	if (fp==NULL) {
	*lines = 0;
    *words = 0;
    *chars = 0;
    return -1;
	} 
    int c;
    long l=0;
    long w=0;
    long ch=0;
    int in_space=1;
    
    while ((c=fgetc(fp))!=EOF){
    	ch++;
    	
    	if ( c=='\n' ) l++;
    	
    	if(isspace((unsigned char)c)){
    		in_space=1;
		}else {
			if (in_space)
			w++;
			in_space=0;
		}
	}
    *lines=l;
    *words=w;
    *chars=ch;
    fclose(fp);
    
    return 0;
}

int main(void)
{
    long lines, words, chars;
    int rc;

    make_sample(SAMPLE);

    rc = count_text(SAMPLE, &lines, &words, &chars);
    printf("count_return = %d\n", rc);
    printf("lines = %ld\n", lines);
    printf("words = %ld\n", words);
    printf("chars = %ld\n", chars);

    rc = count_text("d13_ex2_missing.txt", &lines, &words, &chars);
    printf("missing_count_return_nonzero = %d\n", rc != 0);
    printf("counters_cleared_on_failure = %d\n",
           lines == 0 && words == 0 && chars == 0);

    remove(SAMPLE);
    return 0;
}
