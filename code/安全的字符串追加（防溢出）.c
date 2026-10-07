/* ex_2_safe_cat.c —— 练习 2 骨架：安全的字符串追加（防溢出）
 *
 * 要求
 *   实现 int safe_cat(char *dst, unsigned cap, const char *src)：
 *     - dst 是已经以 '\0' 结尾的字符串，cap 是 dst 这块内存的总容量（字节数）；
 *     - 把 src 追加到 dst 末尾，必须始终保证 dst 以 '\0' 结尾；
 *     - 全部放下返回 1；容量不够时截断并返回 0（绝不允许写出 cap 之外）；
 *     - 你已经放满了（没有多余空间）时返回 0，不改动 dst。
 *
 * 验收标准
 *   填完 TODO 后运行，sol_2_safe_cat.c 的输出就是标准答案。
 *
 * 想一想：为什么这个函数必须收 cap？如果只收 dst 和 src 会怎样？
 */
#include <stdio.h>
#include <string.h>

int safe_cat(char *dst, unsigned cap, const char *src)
{
    unsigned used;
    unsigned room;
    unsigned need;
    
    if(dst==NULL||cap<=0||src==NULL) return 0;
    
    used=strlen(dst)+1;
    need=strlen(src)+1;
    
    room=cap-used;
    
    if(room==0) return 0;
    
    if(room>=need){
    	strcat(dst,src);
    	return 1;
	}
	
	if(room<need){
		strncat(dst,src,room);
	}
    
    return 0;
}

int main(void)
{
    char buf[8];
    int ok;

    buf[0] = '\0';

    ok = safe_cat(buf, (unsigned)sizeof buf, "abc");
    printf("1) ret = %d, buf = \"%s\" (len %u)\n", ok, buf, (unsigned)strlen(buf));

    ok = safe_cat(buf, (unsigned)sizeof buf, "XYZ");
    printf("2) ret = %d, buf = \"%s\" (len %u)\n", ok, buf, (unsigned)strlen(buf));

    ok = safe_cat(buf, (unsigned)sizeof buf, "0123456789");
    printf("3) ret = %d, buf = \"%s\" (len %u)\n", ok, buf, (unsigned)strlen(buf));

    ok = safe_cat(buf, (unsigned)sizeof buf, "!!!!");
    printf("4) ret = %d, buf = \"%s\" (len %u)\n", ok, buf, (unsigned)strlen(buf));

    return 0;
}
