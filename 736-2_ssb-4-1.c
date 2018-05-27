#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node*next;
           } node;
typedef node*stack;
 
typedef enum {false, true} bool;
 
stack head=NULL;
 
int init(stack*top){
    *top=NULL;
    return 1;
}
 
bool isEmpty(stack top) {
    if(top==NULL)
        {
            return true;
        }
    else
        {
            return false;
        }
            }
           
int add(stack*s, int value){
    if(*s==NULL){
        stack tmp=(stack)malloc(sizeof(node));
        tmp->data=value;
        tmp->next=NULL;
        head=tmp;
    }
    else{
        stack tmp=malloc(sizeof(node));
        tmp->data=value;
        tmp->next=(*s);
        head=tmp;
    }
}
 
int pop(stack *head){
    stack tmp=(*head)->next;
    int value=(*head)->data;
    free(*head);
    (*head)=tmp;
    return value;
}
int top(stack head){
    if(head!=NULL) {return(head->data);}
}
int print(stack*s){
    while((*s)!=NULL)
        {
        printf("%d", ((*s)->data));
        printf(" ");
        s=&((*s)->next);
        }
    printf("\n");
        return 1;
             }
             
int destroy(stack *top) {
   
    stack x,y;
    x=*top;
    y=*top;
   
    while (x!=NULL)
    {
        y=x->next;
        free(x);
        x=y;
    }
    free(*top);
    return 1;
                }
               
int main() {
    init(&head);
    int value, n, i;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &value);
        add(&head, value);
    }
    print (&head);
    printf("%d\n", pop(&head));
    printf("\n");
    print(&head);
    destroy(&head);
    return 0;
        }
