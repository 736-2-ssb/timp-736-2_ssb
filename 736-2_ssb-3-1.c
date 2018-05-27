#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
            } node;
 
typedef node *list;
typedef enum {false, true} bool;
list head=NULL;
list tail=NULL;
 
int init(list *root) {
   
    *root=NULL;
    return 1;
             }
 
int destroy(list *root) {
   
    list x,y;
    x=*root;
    y=*root;
   
    while (x!=NULL)
    {
        y=x->next;
        free(x);
        x=y;
    }
    free(*root);
    return 1;
                }
 
 
bool isEmpty(list root) {
 
    if (root==NULL)
        {
             return true;
        }
    else
        {
            return false;
        }
               }
 
list find(list root, int value){
    list tmp=root;
    while(tmp!=NULL)
        {
            if(tmp->value==value)
                    {
                    return tmp;
                    } else return 0;
        }
                }
           
 
 
int append(list *lst, int value){
   
    if ((*lst)==NULL)
        {
            list tmp=(list)malloc(sizeof(node));
            tmp->next=NULL;
            tmp->value=value;
            tmp->prev=NULL;
            head=tmp;
            tail=tmp;
            return 1;
        }
    list tmp=malloc(sizeof(node));
    tmp->value=value;
    tmp->prev=(*lst);
    if ((*lst)==tail)
        {
            tmp->next=NULL;
            ((*lst)->next)=tmp;
            tail=(*lst)->next;
        }
    else
        {
            tmp->next=((*lst)->next);
            ((*lst)->next)->prev=tmp;
            ((*lst)->next)=tmp;
        }
        return 1;
                    }
       
   
int prepend(list *lst, int value){
   
    if ((*lst)==NULL);
        {
	    list tmp=(list)malloc(sizeof(node));
            tmp->next=NULL;
            tmp->value=value;
            tmp->prev=NULL;
            head=tmp;
            tail=tmp;
            return 1;
        }
   
    list tmp=malloc(sizeof(node));
    tmp->value=value;
    tmp->next=(*lst);
 
    if((*lst)==head)
        {
            tmp->prev=NULL;
            ((*lst)->prev)=tmp;
            head=(*lst)->prev;
        }
    else
        {
            printf("1");
		tmp->prev=((*lst)->prev);
            ((*lst)->prev)->next=tmp;
            ((*lst)->prev)=tmp;
        }
        return 1;
                    }
 
int rmv(list *lst){
 
    list x;
        x=(*lst);
    if((*lst)==head)
    {
        ((*lst) -> next) -> prev = NULL;
        head = ((*lst) -> next);
        free((x));
	return 1;
    }
    else if ((*lst) == tail)
    {
        ((*lst) -> prev) -> next = NULL;
        tail = ((*lst) -> prev);
        free((x));
	return 1;
    }
    else
    {
        ((*lst) -> next) -> prev = ((*lst) -> prev);
        ((*lst) -> prev) -> next = ((*lst) -> next);
        free((x));
	return 1;
    }
	return 1;
}
int print(list *lst){
    while((*lst)!=NULL)
        {
        printf("%d", (*lst)->value);
        printf(" ");
        lst=&((*lst)->next);
        }
    printf("\n");
        return 1;
             }
int rmv_k(list*lst,int k)
{
    list tmp;
    int q=1;
    tmp=(*lst);
    while(true)
    {
        if(k==q)
        {
        rmv(&tmp);
        break;
        }
    (tmp)=(tmp)->next;
     q=q+1;
    }
    return 1;
}
 
int main()
{
    init(&head);
    int a,b,i, n, k, m, c, d, value;
    list tp;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &value);
        append(&tail, value);
    }
    print(&head);
    scanf("%d", &k);
    rmv_k(&head,k);
    
    print(&head);
    scanf("%d",&m);
    tp=head;
    while (1)
    {if ((tp->value)==m)
    {
       rmv(&tp);
        break;
    }
   tp=tp->next;
    }
   
    print(&head);
    tp=NULL;
    
   scanf("%d",&a);
   scanf("%d",&b);
   tp=head;
   for (i=1; i<a; i++)
   {
      tp=tp->next;
   }
   append(&tp,b);
   print(&head);
   tp=NULL;
   tp=head;

   scanf("%d", &c);
   scanf("%d", &d);

   for( i=1; i<(c-1); i++)
   {
      tp=tp->next;
   }
   append(&tp, d);
   print (&head);
   destroy(&head);
   return 0;

}
