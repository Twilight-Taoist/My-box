#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

//尾插
void push_back(struct node **head, int v){
	struct node *n=malloc(sizeof(*n));
	if (n==NULL){
		return ;
	}
	n->data=v;
	n->next=NULL;
	struct node **pp=head;
	if(*head==NULL){*head=n;return;}
	while ((*pp)!=NULL){
		pp=&(*pp)->next;
	}
	(*pp)=n;
}     
//查找 
static int find(const struct node *head,int v){
	const struct node *n=NULL;
	int i=0;
	n=head;
	while (n!=NULL){
		if (n->data==v){
			i++;
		}
		n=n->next;
	}
	return i;
} 
// 删除（所有匹配）
static void delete_value(struct node **head, int v){
	struct node **pp=NULL;
	pp=head;
	while((*pp)!=NULL){
		struct node *n;
		if ((*pp)->data==v){
			n=(*pp);
			(*pp)=(*pp)->next;
			free(n);
		}else {pp=&(*pp)->next;}
	}
}   
 // 打印
static void print(const struct node *head){
	const struct node *n=NULL;
	for (n=head;n!=NULL;n=n->next){
		printf (" %d ",n->data);
	}
}
static void free_all(struct node *head){
	while (head!=NULL){
		struct node *n=NULL;
		n=head;
		head=head->next;
		free(n);
	}
}

static int update(struct node *head,int old_v,int new_v){
	struct node *n=NULL;
	n=head;
	int i=0;
	while (n!=NULL){
		if (n->data==old_v){
			n->data=new_v;
			i++;
		}
		n=n->next;
	}
	return i;
}

int main ()
{   
    struct node *head1=NULL;
    push_back(&head1,0);
	push_back(&head1,1);
	push_back(&head1,1);
	push_back(&head1,2);
	push_back(&head1,2);
	int i=0;
	i=find(head1,1);
	printf (" %d ",i);
	print(head1);
	i=0;
	delete_value(&head1,1);
    i=update(head1,2,6);
    printf("%d",i);
	printf("\n");
	print(head1);
	free_all(head1);
		
    return 0;	
}

             
