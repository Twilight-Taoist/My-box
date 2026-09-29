/* ex_2_delete_one.c —— 练习 2 骨架：删除第一个值为 v 的节点
 *
 * 要求
 *   1. 签名固定为：int delete_value(struct node **head, int v)
 *      —— 用「指向指针的指针」，因为删除头节点时 head 本身要改；
 *   2. 删到返回 1，没找到返回 0；
 *   3. **先摘链，再 free**；摘链这一步必须让"指向这个节点的那个指针"跳过它；
 *   4. 头节点、中间节点、尾节点三种情况都要能正确删除，而且**不需要**为它们分别写分支。
 *
 * 验收标准
 *   填完 TODO 后运行，输出必须是：
 *       deleted(3)  = 1, list: 1 2 4 5
 *       deleted(1)  = 1, list: 2 4 5
 *       deleted(5)  = 1, list: 2 4
 *       deleted(99) = 0, list: 2 4
 *
 * 提示：想清楚 `*pp` 到底是谁——一开始它是 head，往后走之后它是"上一个节点的 next"。
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

static int delete_value(struct node **head, int v)
{
    struct node **pp=head;
    
    while ( (*pp)!=NULL && (*pp)->data!=v){
    	pp=&(*pp)->next;
	}
    if ( (*pp)==NULL ) return 0 ;
    
    struct node *n;
    
    n=(*pp);
    (*pp)=n->next;
    
    free(n);
    
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
    int i;
    struct node *head = make(1);
    struct node *p = head;

    for (i = 2; i <= 5; i++) {
        p->next = make(i);
        p = p->next;
    }

    printf("deleted(3)  = %d, list: ", delete_value(&head, 3));  print_list(head);
    printf("deleted(1)  = %d, list: ", delete_value(&head, 1));  print_list(head);
    printf("deleted(5)  = %d, list: ", delete_value(&head, 5));  print_list(head);
    printf("deleted(99) = %d, list: ", delete_value(&head, 99)); print_list(head);

    free_list(head);
    head = NULL;

    return 0;
}
