#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

static struct  node *make(int v){
	struct node *n=malloc(sizeof *n);
	if ( n==NULL){
		printf ("bad1");
		exit (1);
	}
	n->data=v;
	n->next=NULL;
	return n;
}

// 版本 1：返回新 head
struct node *push_front_v1(struct node *head, int v) {
	struct node *n =malloc(sizeof (*n));
	if (n==NULL ){
		printf ("bad2");
		exit (1);
	}
	if (head==NULL){
		n=make(0);
	}else {
	n->data=v;
	n->next=head;
	}
	return n;
	
}
// 版本2，二级指针 
void push_front_v2(struct node **head, int v) {
	struct node *n =malloc(sizeof(*n));
	if (n==NULL ){
		printf("bad3");
		exit (1);
	}
	n->data=v;
	n->next=*head;
	*head=n;/* head=n是想要n成为head所指的下一个函数，但是这个函数中的head是拷贝进来的，
	不是原来的head，head=n出了函数就没用了；而**head的*head指的是head，所以可以。 
	 */
} 

static int count(const struct node *head){
	const struct node *p=head;
	if ( p==NULL ){
		printf ("bad4");
		return 0;
	}
	int i=0;
	while (p!=NULL){
		i++;
		p=p->next;
	}
	return i;
	
} 
// 返回新 head
struct node *delete_head_v1(struct node *head){

	if(head !=NULL ){
    struct node *delete_head=head->next;
	free(head);
	return delete_head;
	}else { 
	printf ("list=0");
	return head;
	}
}
  // 二级指针  
void delete_head_v2(struct node **head){
	if( head==NULL||*head==NULL){
		printf ("bad5");
		exit (1);
	}
	struct node *delete_head;
	delete_head=*head;
	*head=(*head)->next;
	free(delete_head);	
	
} 
  
void free_list(struct node *head){
	struct node *temp;
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
}


int main ()
{
	struct node *head=make(1);
	head->next=make(2);
	head->next->next=make(3);
	
	printf ("%d\n",count (head));
	head=push_front_v1(head,4);
	printf ("%d\n",count (head));
	printf ("%d\n",head->data);
	
	
	push_front_v2(&head,5);
	printf ("%d\n",count (head));    
	printf ("%d\n",head->data);
	head=delete_head_v1(head);
	printf ("%d\n",count (head));
	printf ("%d\n",head->data);
	delete_head_v2(&head);
	printf ("%d\n",count (head));
	printf ("%d\n",head->data);
	free_list(head);
	head=NULL;
	
	return 0;
}
