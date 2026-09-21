/* ex_w4_push_pp.c —— 第 2 轮 W4 填空骨架（台账 E6 / 考点 E09-3）
 *
 * 只填 push_front 的函数体（4 个 TODO），main / print_list / free_list 都给你写好了。
 * 填完在 Dev-C++ 里按 F11 运行（`ex_` 前缀在 build.ps1 里只编译不运行）。
 *
 * 验收标准 —— 填对之后应该看到：
 *     push_front(&head,1) = 1
 *     push_front(&head,2) = 1
 *     push_front(&head,3) = 1
 *     list: 3 2 1
 *     push_front(NULL,9)  = 0  (guard path: must not crash)
 *     freed 3 node(s)
 *
 * 现在（还没填）会看到：三行 = 0、list 是空的、freed 0 —— 那是正常的，说明你还没实现。
 * 参考答案在 sol_w4_push_pp.c，**先自己填，卡住再看**。
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

static int push_front(struct node **head, int v)
{
    struct node *n=NULL;
    if (head==NULL) return 0;;
    n=malloc(sizeof(*n));
    if (n==NULL) return 0;
    n->data=v;
    n->next=*head;
    *head=n;
    /* 填完实现后，这一行可以删掉 */
    return 1;
}

static void print_list(const struct node *head)
{
    const struct node *p;
    for (p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

static int free_list(struct node *head)
{
    int n = 0;
    while (head != NULL) {
        struct node *next = head->next;
        free(head);
        head = next;
        n++;
    }
    return n;
}

int main(void)
{
    struct node *head = NULL;

    printf("push_front(&head,1) = %d\n", push_front(&head, 1));
    printf("push_front(&head,2) = %d\n", push_front(&head, 2));
    printf("push_front(&head,3) = %d\n", push_front(&head, 3));

    printf("list: "); print_list(head);

    printf("push_front(NULL,9)  = %d  (guard path: must not crash)\n", push_front(NULL, 9));

    printf("freed %d node(s)\n", free_list(head));
    head = NULL;

    return 0;
}
