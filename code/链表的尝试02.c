#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

//插头 ,返回n 
static struct node *push_front_v1 (struct node *head ,int v){
	struct node *n=malloc(sizeof(*n));
	if (n==NULL){
		printf ("no malloc");
		return NULL;
	}
	n->data=v;
	n->next=head;
	
	return n;
}
//插头，二级指针
static void push_front_v2 (struct node **head,int v){
	struct node *n=malloc(sizeof (*n));
	if (n==NULL){
		printf ("no malloc");
		return;
	}
	n->data=v;
	n->next=*head;
	*head=n;	
} 

//插尾，返回head；
static struct node *push_back_v1(struct node *head ,int v){
	struct node *n=malloc(sizeof (*n));
	if (n==NULL){
		printf ("no malloc");
		return head;
	}
	n->data=v;
	n->next=NULL;
	if (head==NULL){return n;}
	struct node *p;
	for( p=head;p->next!=NULL;p=p->next);
	p->next=n;
	return head;
} 
//插尾，二级指针
static void push_back_v2 (struct node **head, int v){
	struct node *n=malloc(sizeof (*n));
	if (n==NULL){
		printf ("no malloc");
		return ;
	}
	n->data=v;
	n->next=NULL;
	if (*head==NULL){*head=n;return;}
	struct node **pp=head;
	while (*pp!=NULL){
		pp=&(*pp)->next;
	}
	*pp=n;
}
//遍历
static void go_list (const struct node *head){
	const struct node *p;
	if (head==NULL){
		printf("0");
	}
	for (p=head;p!=NULL;p=p->next){
		printf ("%d ",p->data);
	}
} 
//查找
static int index_of (const struct node *head ,int v){
	const struct node *p;
	int i=0;
	for ( p=head; p!=NULL ;p=p->next,i++){
		if (p->data==v){
			return i;
		}
	}
	return -1;
} 
// 删掉第一个值为 v 的节点；删到返回 1，没找到返回 0 
static int delete_value(struct node **head, int v){
	if ( *head==NULL){
//		printf ("0=head");
		return 0;
	}
	struct node **pp=head;
	int cnt=0;
	while (*pp!=NULL){
	if ( (*pp)->data==v ){
		struct node *n;
		n=*pp;
		(*pp)=(*pp)->next;
		free(n);
		cnt++;
//		return 1;
	//删除全部类型的v节点只需删除return； 
	   }else { pp=&(*pp)->next;}
	}
	return cnt;	
}//该函数可以处理头，尾，中间； 
static void free_list (struct node *head){
	while (head !=NULL){
	    struct node *n;
	    n=head;
	    head=head->next;
	    free(n);
    }
}
int delete_last(struct node **head){
	if (*head==NULL){
		return 0;
	}
	struct node **pp=head;
	while ((*pp)->next!=NULL){
	   pp=&(*pp)->next;
	   }
	free(*pp);
	*pp=NULL;
	return 1;
	
}  // 删到返回 1；空链表返回 0
static void delete_all(struct node **head){
    while (*head != NULL){
        struct node *n = *head;
        *head = n->next;    
        free(n);
    }
}

// 返回第一个值为 v 的**节点指针**；找不到返回 NULL
struct node *find(struct node *head, int v){
	struct node *n;
	if (head==NULL){
		return head;
	}
	for (n=head ;n!=NULL && n->data!=v;n=n->next );
	return n;	 
}
 // 把所有 old_v 改成 new_v，返回改了几个
int update(struct node *head, int old_v, int new_v){
	struct node *n;
	int cnt=0;
	n=head;
	while(n!=NULL){
		if (n->data==old_v){
			n->data=new_v;
			cnt++;
		}
		n=n->next;
	}
	return cnt;
}  
// 在下标 pos 处插入；越界返回 0
int insert_at(struct node **head, int pos, int v){
	struct node *n=malloc(sizeof(*n));
	if (n==NULL){
		return 0;
	}
	n->data=v;
	struct node **pp=head;
	int i=0;
	
	while ((*pp)!=NULL && i<pos){
		pp=&(*pp)->next;
		i++;
	}
	if ((*pp)==NULL && i<pos){
		free (n);
		return 0;
	}
	
	n->next=(*pp);
	*pp=n;
	return 1;
}   
/* 数一数链表里值为 v 的节点有几个 */
static int count_value(const struct node *head, int v){
	const struct node *n = head;
	int i = 0;
	while (n != NULL){
		if (n->data == v) i++;
		n = n->next;
	}
	return i;
}
int main ()
{
	struct node *head1=NULL;
	head1=push_front_v1(head1,0);
	head1=push_front_v1(head1,1);
	head1=push_front_v1(head1,1);	
	head1=push_front_v1(head1,2);
	go_list(head1);
	int i=0;
	int k=0;
	i=delete_value(&head1,1);
	k=delete_last(&head1);
	printf("%d %d\n",i,k);
	go_list(head1);
	
	struct node *head2=NULL;
	push_front_v2(&head2,0);
	push_front_v2(&head2,3);
	push_front_v2(&head2,3);
	push_front_v2(&head2,4);
	go_list(head2);
	
	int b=-1;
	b=insert_at(&head2,1,6);
	printf("b= %d ",b);
	go_list(head2);
	
	
	struct node *n=NULL;
	n = find(head2, 4);
    if (n != NULL) {
	    printf ("n->data= %d ", n->data);
	}else {printf ("not found ");}
	int a=0;
	a=update(head2,3,5);
	go_list(head2);	
	printf(" %d ",a);
	
	printf("\n");
	struct node *head3=NULL;
	head3=push_back_v1(head3,0);
	head3=push_back_v1(head3,1);
	go_list(head3);
	printf("\n");
	push_back_v2(&head3,2);
	int j=0;
	j=index_of(head3,2);
	printf("%d ",j);
	go_list(head3);
	
	int d=0;
	d=count_value(head3,1);
	printf("%d",d);
		
	free_list(head1);
	free_list(head2);
	delete_all(&head3);
	head1=NULL;
	head2=NULL;
	return 0;
}





