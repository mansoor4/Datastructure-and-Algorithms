#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *first=NULL;
void create(int A[],int n);
void display(struct Node *p);
void Rdisplay(struct Node *P);
int count(struct Node *p);
int Rcount(struct Node *p);
int max(struct Node *p);
int Rmax(struct Node *p);
int sum(struct Node *p);
int Rsum(struct Node *p);
void countAndSum(struct Node *p);
void RcountAndSum(struct Node *p);
void searching(struct Node *p,int n);
void insert(struct Node*p,int possition,int n );
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
       t=(struct Node*) malloc(sizeof(struct Node));
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void Rdisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}
int count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
int Rcount(struct Node *p)
{
    if(p!=NULL)
    {

        return(Rcount(p->next)+1);
    }

    else
        return 0;
}
int max(struct Node *p)
{
   int max=p->data;
    while(p!=NULL)
    {
        if(p->data>max)
        {
            max=p->data;
        }
            p=p->next;
    }
    return max;
}
int Rmax(struct Node *p)
{
    static int max;
    if(p!=NULL)
    {
        if(p->data>max)
            max=p->data;
        Rmax(p->next);
    }
    return max;
}
int sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int Rsum(struct Node *p)
{

    if(p!=NULL)
    {
        return(Rsum(p->next)+p->data);
    }
    else
        return 0;
}
void countAndSum(struct Node *p)
{
    int count=0,sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        count++;
        p=p->next;
    }
    printf("\nThe sum and count of the linked list is %d %d ",sum,count);
}
void RcountAndSum(struct Node *p)
{

    static int sum=0,count=0;
    if(p!=NULL)
    {
       sum+=p->data;
       count++;
       RcountAndSum(p->next);
    }
    else
    printf("\nThe sum and count of the linked list is %d %d ",sum,count);
}
void searching(struct Node *p,int n)
  {
      int search=1;
      while(p!=NULL)
      {
          if(p->data==n)
          {
           break;
          }
          search++;
          p=p->next;

      }
      if(search<=5)
      printf("The possition of the element %d is %d",n,search);
      else
        printf("The element is not found");
      }
void insert(struct Node*p,int possition,int n)
{
    struct Node *t;
    if(possition==1)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=n;
        t->next=first;
        first=t;
    }
    else
    {
        int i;
        for(i=1;i<possition && p;i++)
        {
            p=p->next;
        }
        if(p)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=n;
            t->next=p->next;
            p->next=t;
        }
    }
}
int main()
{
    int a[]={1,4,6,5,2};
    create(a,5);
    insert(first,3,7);
    insert(first,1,10);
    display(first);
    return 0;
}
