/* ex_w7_delete_at.c —— 第 2 轮 W7 填空骨架（台账 E11 / d17）
 *
 * 只填 delete_at 的函数体（4 个 TODO），main / print_list 给你写好了。
 * 填完在 Dev-C++ 里按 F11 运行（`ex_` 前缀在 build.ps1 里只编译不运行）。
 *
 * 要交的东西：
 *   int delete_at(struct node **head, int pos);
 *   - 删除第 pos 个节点（pos 从 0 开始）；删到返回 1，越界/非法/空链表返回 0；
 *   - 用「指向指针的指针」，**不许为 pos == 0 单独写分支**；先摘链再 free。
 *
 * 验收标准 —— 填对之后应该看到：
 *     start: 10 20 30 40
 *     delete_at(&head,1)  = 1, list: 10 30 40
 *     delete_at(&head,0)  = 1, list: 30 40
 *     delete_at(&head,5)  = 0, list: 30 40
 *     delete_at(&head,-1) = 0, list: 30 40
 *     delete_at(&head,1)  = 1, list: 30
 *     delete_at(&head,0)  = 1, list: (empty list)
 *     delete_at(&head,0)  = 0, list: (empty list)
 *
 * 参考答案在 sol_w7_delete_at.c，**先自己填**。
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

static struct node *make(int v)
{
    struct node *n = malloc(sizeof *n);
    if (n == NULL)
        exit(1);
    n->data = v;
    n->next = NULL;
    return n;
}

static void print_list(const struct node *head)
{
    const struct node *p;

    if (head == NULL) {
        printf("(empty list)\n");
        return;
    }
    for (p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

static int delete_at(struct node **head, int pos)
{
    struct node **pp = head;
    int i;

    if (head==NULL || pos<0 ) return 0;/* TODO ① 容错：head == NULL 或 pos < 0 时返回 0 */
    for (i=0; i<pos && (*pp)!=NULL;pp=&(*pp)->next,i++ );/* TODO ② 让 pp 一路走到「第 pos 个节点的地址存放处」 */
    if ((*pp)==NULL) return 0;/* TODO ③ 越界判断：*pp == NULL 说明链表没这么长，返回 0 */
    struct node *n;
	n=(*pp);
	(*pp)=n->next;
	free (n);  /* TODO ④ 摘链（*pp = victim->next）之后再 free(victim)，返回 1 */

  /* 填完实现后，这一行可以删掉 */
    return 1;
}

int main(void)
{
    struct node *head = make(10);

    head->next = make(20);
    head->next->next = make(30);
    head->next->next->next = make(40);

    printf("start: "); print_list(head);
    printf("delete_at(&head,1)  = %d, list: ", delete_at(&head, 1));  print_list(head);
    printf("delete_at(&head,0)  = %d, list: ", delete_at(&head, 0));  print_list(head);
    printf("delete_at(&head,5)  = %d, list: ", delete_at(&head, 5));  print_list(head);
    printf("delete_at(&head,-1) = %d, list: ", delete_at(&head, -1)); print_list(head);
    printf("delete_at(&head,1)  = %d, list: ", delete_at(&head, 1));  print_list(head);
    printf("delete_at(&head,0)  = %d, list: ", delete_at(&head, 0));  print_list(head);
    printf("delete_at(&head,0)  = %d, list: ", delete_at(&head, 0));  print_list(head);

    free(head);
    head = NULL;

    return 0;
}
