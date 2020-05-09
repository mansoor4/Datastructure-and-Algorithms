#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node*next;
}*head=NULL;
void create(int A[],int n);
void display(struct Node*p);
void checkCircularList();
void Rdisplay(struct Node*p);
void insert(struct Node*p,int position,int n);
void Delete(struct Node*p,int position);

void create(int A[],int n)
{
    struct Node*t,*follow=NULL;
    int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[0];
    t->next=NULL;
    head=t;
    follow=t;
    for(i=1;i<n;i++)
    {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    follow->next=t;
    follow=t;
    }
    follow->next=head;

}
void checkCircularList()
{
    struct Node *p=head,*q=head;
    do
    {
        p=p->next;
        q=q->next;
        if(q->next)
            q=q->next;
            else
                q=NULL;
    }while(p && q && p!=q);
    if(p==q)
    {
        printf("The linked list is circular");
    }
    else
        printf("The linked list is not circular");
}
void display(struct Node*p)
{
do
{
    printf("%d ",p->data);
    p=p->next;
}
while(p!=head);



}
void Rdisplay(struct Node*p)
{
static int flag=1;
if(p!=head || flag==1)
{
    printf("%d ",p->data);
    flag=0;
    Rdisplay(p->next);
}
}
void insert(struct Node*p,int position,int n)
{
    struct Node*t,*follow=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=n;
    t->next=NULL;
    int i;
    if(position==1)
    {
        if(head!=NULL)
        {
       do
       {
           p=p->next;
       }while(p->next!=head);
        t->next=head;
        head=t;
        p->next=head;
        }
        else
        {
            head=t;
            head->next=head;
        }
    }
    else
    {
        for(i=1;i<position;i++)
        {
            follow=p;
            p=p->next;
        }
        t->next=follow->next;
        follow->next=t;
    }
}
void Delete(struct Node*p,int position)
{
    struct Node*follow=NULL;
    int i,x;
    if(position==1)
    {
        while(p->next!=head)
            p=p->next;
        follow=head;
        x=head->data;
        head=head->next;
        p->next=head;
        free(follow);

    }
    else
    {
        for(i=1;i<position;i++)
        {
            follow=p;
            p=p->next;
        }
        x=p->data;
        follow->next=p->next;
        free(p);
    }
    printf("The element delete from %d position is %d\n",position,x);
}
int main()
{
int a[]={1,2,3,4,5};
create(a,5);
display(head);
printf("\n");
Delete(head,2);
Delete(head,1);
Delete(head,3);
display(head);
 return 0;
}
