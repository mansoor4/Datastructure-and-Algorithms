#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
}*first=NULL;
void create(int A[],int n);
void display(struct Node*p);
void insert(struct Node*p,int pos,int n);
void Delete(struct Node*p,int pos);
void Reverse(struct Node*p);
void create(int A[],int n)
{
    struct Node*t,*follow=NULL;
    int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[0];
    t->prev=NULL;
    t->next=NULL;
    first=t;
    follow=t;
    for(i=1;i<n;i++)
    {
      t=(struct Node*)malloc(sizeof(struct Node));
      t->data=A[i];
      t->next=NULL;
      follow->next=t;
      t->prev=follow;
      follow=t;
    }
}
void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void insert(struct Node*p,int pos,int n)
{
    struct Node*t,*follow=NULL;
    int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->next=NULL;
    t->data=n;
    if(pos==1)
    {
        if(first==NULL)
        {
            first=t;
            first->prev=NULL;
        }
        else
        {
            t->next=first;
            first->prev=t;
            t->prev=NULL;
            first=t;
        }
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            follow=p;
            p=p->next;
        }
        t->next=follow->next;
        t->prev=follow;
        if(follow->next)
        {
        follow->next->prev=t;
    }
    follow->next=t;
}
}
void Delete(struct Node*p,int pos)
{
    struct Node*follow=NULL;
    int i,x;
 if(pos==1)
 {
     first=first->next;
     first->prev=NULL;
     x=p->data;
     free(p);
 }
 else
 {
     for(i=1;i<pos;i++)
     {
         follow=p;
         p=p->next;
     }
     follow->next=p->next;
     p->next->prev=follow;
     x=p->data;
     free(p);

 }
 printf("The deleted element is %d\n",x);
 }
 void Reverse(struct Node*p)
{
    struct Node*temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        {
            first=p;
        }
    }
}
int main()
{
   int a[6]={1,2,3,4,5,6};
create(a,6);

Reverse(first);
display(first);
    return 0;
}
