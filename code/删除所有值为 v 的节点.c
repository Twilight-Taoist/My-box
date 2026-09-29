/* ex_3_delete_all.c —— 练习 3 骨架：删除**所有**值为 v 的节点
 *
 * 要求
 *   1. 签名固定为：int delete_all(struct node **head, int v)
 *   2. 返回实际删掉的节点个数；
 *   3. 要能处理：连续多个匹配、开头的连续多个匹配、尾部的匹配、全部删完（链表变空）；
 *   4. 同样的规矩：先摘链再 free；不许泄漏、不许重复释放。
 *
 * 验收标准
 *   填完 TODO 后运行，输出必须是：
 *       removed 3, list: 1 3 4
 *       removed 1, list: 3 4
 *       removed 0, list: 3 4
 *       removed 1, list: 4
 *       removed 1, list: (empty list)
 *
 * 注意，这里有一个很容易踩的坑：**删掉一个节点之后，能不能立刻往后走？**
 *    想一想链表里连着两个 2 的时候会发生什么，再动手写。
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

static int delete_all(struct node **head, int v)
{
    struct node **pp=head;
	int i=0;
	
	while((*pp)!=NULL){
		if((*pp)->data==v){
			struct node *n;
			n=(*pp);
			(*pp)=n->next;
			free (n);
			i++;
		}else {
			pp=&(*pp)->next;
		}
		
	}
	 
    
    return i;
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
    const int data[6] = {2, 2, 1, 2, 3, 4};
    struct node *head = make(data[0]);
    struct node *p = head;

    for (i = 1; i < 6; i++) {
        p->next = make(data[i]);
        p = p->next;
    }

    printf("start   : "); print_list(head);

    printf("removed %d, list: ", delete_all(&head, 2)); print_list(head);
    printf("removed %d, list: ", delete_all(&head, 1)); print_list(head);
    printf("removed %d, list: ", delete_all(&head, 9)); print_list(head);
    printf("removed %d, list: ", delete_all(&head, 3)); print_list(head);
    printf("removed %d, list: ", delete_all(&head, 4)); print_list(head);

    free_list(head);
    head = NULL;

    return 0;
}
