/* ex_1_copy_file.c -- 编程题 C4-1 的填空骨架：写一个"一个字节都不许丢"的复制
 *
 * 只填带 TODO 的地方；函数名、参数、返回值约定不要改（参考答案 sol_1 用的是同一套）。
 * 编译要求：零警告（未使用的参数请用 (void)参数名; 消掉）。
 *
 * 验收标准（跑起来之后自己对照）：
 *   copy_return = 0       成功
 *   dst_size 和 src_size 相等
 *   identical = 1         两个文件逐字节相同
 *   源文件不存在时返回非 0，而且**不破坏**已经存在的目标文件
 *
 * 提示：fgetc / fputc 的返回值是 int，因为它要能表示 EOF；
 *       打开模式用 "rb" / "wb"，复制工具不该改文件内容。
 */
#include <stdio.h>

#define SRC     "d13_ex1_src.txt"
#define DST     "d13_ex1_dst.txt"
#define MISSING "d13_ex1_missing.txt"

/* 造一个样本文件（这段已经写好了） */
void make_sample(const char *path)
{
    FILE *fp = fopen(path, "w");

    if (fp == NULL) return;
    fputs("line one\nline two\nline three\n", fp);
    fclose(fp);
}

/* 文件字节数；打不开返回 -1（这段已经写好了） */
long file_size(const char *path)
{
    FILE *fp = fopen(path, "rb");
    long n;

    if (fp == NULL) return -1;
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    fclose(fp);
    return n;
}

/* 两个文件是否逐字节相同（这段已经写好了） */
int same_bytes(const char *a, const char *b)
{
    FILE *fa = fopen(a, "rb");
    FILE *fb = fopen(b, "rb");
    int ca, cb, ok = 1;

    if (fa == NULL || fb == NULL) {
        if (fa != NULL) fclose(fa);
        if (fb != NULL) fclose(fb);
        return 0;
    }
    do {
        ca = fgetc(fa);
        cb = fgetc(fb);
        if (ca != cb) { ok = 0; break; }
    } while (ca != EOF);
    fclose(fa);
    fclose(fb);
    return ok;
}

/* TODO: 实现它。
 * 成功返回 0；源文件打不开返回 -1；目标文件建不出来返回 -2；
 * 写失败返回 -3；fclose 报告失败返回 -4（fclose 的返回值必须查）。 */
int copy_file(const char *src, const char *dst)
{
	FILE *in, *out;
	int c;
	in=fopen(src,"rb");
	if (in==NULL) return -1;
	
	out=fopen(dst,"wb");
	if (out==NULL){
		fclose(in);
		return -2;
	}
	
	while ((c=fgetc(in))!=EOF){
		if (fputc(c,out)==EOF){
			fclose (in);
			fclose (out);
			return -3;
		}
	}
	
	fclose (in);
	if (fclose(out)!=0){
		return -4;
	}
	
    return 0;
}

int main(void)
{
    int rc;

    remove(MISSING);
    remove(DST);
    make_sample(SRC);
    printf("src_size = %ld\n", file_size(SRC));

    rc = copy_file(SRC, DST);
    printf("copy_return = %d\n", rc);
    printf("dst_size = %ld\n", file_size(DST));
    printf("identical = %d\n", same_bytes(SRC, DST));

    rc = copy_file(MISSING, DST);
    printf("missing_copy_return_nonzero = %d\n", rc != 0);
    printf("dst_untouched_size = %ld\n", file_size(DST));

    remove(SRC);
    remove(DST);
    return 0;
}
