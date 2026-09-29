/* ex_1_list_basics.c —— 练习 1 骨架：建立 / 遍历 / 销毁
 *
 * 要求
 *   1. push_back：把新节点接到链表**末尾**（返回新的表头；空链表时返回的就是新节点）；
 *   2. count_nodes：返回节点个数；
 *   3. sum_all：返回所有 data 之和；
 *   4. free_list：逐个 free，返回释放了几个节点，**不许泄漏**；
 *   5. 全程用临时指针遍历，不许把 head 当游标用。
 *
 * 验收标准
 *   填完 TODO 后运行，输出必须是：
 *       nodes = 4
 *       sum   = 100
 *       destroyed 4 node(s)
 *
 * 提示：push_back 里如果每次都用循环找尾巴，复杂度是 O(n)；
 *       要想 O(1) 就得额外维护一个 tail 指针（想一想它会给删除带来什么麻烦）。
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

static struct node *push_back(struct node *head, int v)
{
    struct node *n=malloc(sizeof(*n));
    if (n==NULL){
    	printf ("fail_malloc\n");
    	return head;
	}
	
	n->next=NULL;
	n->data=v;
	
	if ( head==NULL ) {
		head=n;
		return head;
	}
	
	struct node *p=head;
	
	while ( p->next!=NULL ){
		p=p->next;
	}
	
	p->next=n;
	
    return head;
}

static int count_nodes(const struct node *head)
{
    int n=0;
    const struct node *p;
    
    for( p=head ; p!=NULL ; p=p->next,n++);
    
    return n;
}

static int sum_all(const struct node *head)
{
    int sum=0;
    const struct node *p;
    
    for ( p=head ; p!=NULL ;  sum+=p->data ,p=p->next );
    
    return sum;
}

static int free_list(struct node *head)
{
    int n=0;
    struct node *p;
    
    while (head!=NULL){
    	p=head;
    	head=head->next;
    	free (p);
    	n++;
	}
    
    return n;
}

static void print_list(const struct node *head)
{
    const struct node *p;
    for (p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

int main(void)
{
    struct node *head = NULL;

    (void)make;                 /* 实现 push_back 时就会用到它；先提一下，避免"未使用函数"警告 */

    head = push_back(head, 10);
//    printf("%d\n",head->data);
    head = push_back(head, 20);
    head = push_back(head, 30);
    head = push_back(head, 40);

    print_list(head);
    printf("nodes = %d\n", count_nodes(head));
    printf("sum   = %d\n", sum_all(head));
    printf("destroyed %d node(s)\n", free_list(head));
    head = NULL;

    return 0;
}
