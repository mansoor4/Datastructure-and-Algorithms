#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL,*last=NULL,*first1=NULL,*first2=NULL;
// FUNCTION DECLARTION.
void createSecondLinkedList(int A[],int n);
int count(struct Node*p);
void add(struct Node*p,int n);
void display(struct Node*p);
void insert(struct Node*p,int n,int pos);
void Delete(struct Node*p,int pos);
void sortedOrNot(struct Node*p);
void deleteDouble(struct Node *p);
void reverseLink(struct Node *p);
void RreverseLink(struct Node*p,struct Node*q);
void reverseElement(struct Node *p);
void concateLinkedList(struct Node*p);
void merging(struct Node*p,struct Node*q);
// FUNCTION DEFINITION.
int count(struct Node*p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
void createSecondLinkedList(int A[],int n)
{
    struct Node*t,*follow=NULL;
    int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[0];
    t->next=NULL;
    first1=t;
    follow=t;
    for(i=1;i<n;i++)
    {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    follow->next=t;
    follow=t;
    }
}
void add(struct Node*p,int n)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=n;
    t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}
void display(struct Node*p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void insert(struct Node*p,int n,int pos)
{
    struct Node *t,*q=NULL;
    int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=n;
    if(pos==1)
    {
        t->next=first;
        first=t;
    }
    else
    {
     for(i=1;i<pos;i++)
     {
         q=p;
         p=p->next;
     }
     t->next=q->next;
     q->next=t;
    }
}
void Delete(struct Node*p,int pos)
{
    struct Node*q=NULL;
    int i,x;
    if(pos==1)
    {
        x=p->data;
        first=first->next;
        free(p);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
        free(p);
    }
    printf("The number %d is deleted\n",x);
}
void sortedOrNot(struct Node*p)
{
    int x=-6467565;
    while(p!=NULL)
    {
    if(x>p->data)
    {
        printf("The linked list is not sorted\n");
        break;
    }
    x=p->data;
    p=p->next;
    }
    if(p==NULL)
    {
        printf("The linked list is sorted\n");
    }
}
void deleteDouble(struct Node *p)
{
    struct Node *follow;
    follow=p;
    p=p->next;
    while(p!=NULL)
    {
        if(follow->data==p->data)
        {
            follow->next=p->next;
            free(p);
            p=follow->next;
        }
        else
        {
        follow=p;
        p=p->next;
        }
    }
}
void reverseLink(struct Node *p)
{
   struct Node *q=NULL,*r=NULL;
   while(p!=NULL)
   {
       r=q;
       q=p;
       p=p->next;
       q->next=r;
   }
   first=q;
}
void RreverseLink(struct Node*p,struct Node*q)
{
    if(p!=NULL)
    {
        RreverseLink(p->next,p);
        p->next=q;
    }
    else
        first=q;

}
void reverseElement(struct Node *p)
{
    int i=0;
    int *a;
    a=(int*)malloc(sizeof(int)*count(first));
    while(p!=NULL)
    {
        a[i++]=p->data;
        p=p->next;
    }
    i--;
    p=first;
    while(p!=NULL)
    {
        p->data=a[i--];
        p=p->next;
    }

}
void concateLinkedList(struct Node*p)
{
    while((p->next)!=NULL)
    {
        p=p->next;
    }
    p->next=first1;
}
void merging(struct Node*p,struct Node*q)
{
    struct Node*follow=NULL;
        if((p->data)>(q->data))
        {
        first2=q;
        follow=q;
        q=q->next;
         follow->next=NULL;
    }
    else if((p->data)<(q->data))
    {
       first2=p;
       follow=p;
        p=p->next;
        follow->next=NULL;
    }
    else
    {
        first2=p;
        follow=p;
        p=p->next;
        q=q->next;
        follow->next=NULL;
    }
     while(p!=NULL && q!=NULL)
     {
    if((p->data)>(q->data))
    {
        follow->next=q;
        follow=q;
        q=q->next;
        follow->next=NULL;
    }
    else if((p->data)<(q->data))
    {
       follow->next=p;
       follow=p;
       p=p->next;
       follow->next=NULL;
    }
    else
    {
        follow->next=p;
        follow=p;
        p=p->next;
        q=q->next;
        follow->next=NULL;
    }
}
while(p!=NULL)
{
    follow->next=p;
    follow=p;
    p=p->next;
    follow->next=NULL;
}
while(q!=NULL)
{
    follow->next=q;
    follow=q;
    q=q->next;
    follow->next=NULL;
}
first=first2;
}
int main()
{
    int a[6]={10,20,30,40,50,60};
    createSecondLinkedList(a,6);
    int choice;
    int number,position;
    do
    {
        printf("1.Add\n2.Display\n3.Insert\n4.Delete\n5.Sorted Or Not\n6.Delete Duplicate\n7.Reverse Linked List\n8.Concated linked list\n9.Merging linked list\n10.QUIT\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number to add:");
            scanf("%d",&number);
            add(first,number);
            break;
        case 2:
            display(first);
            break;
        case 3:
            printf("Enter the number and position:");
            scanf("%d%d",&number,&position);
            insert(first,number,position);
            break;
        case 4:
            printf("Enter the position to delete:");
            scanf("%d",&position);
            Delete(first,position);
            break;
        case 5:
            sortedOrNot(first);
            break;
        case 6:
            deleteDouble(first);
            break;
        case 7:
            RreverseLink(first,NULL);
            break;
        case 8:
            concateLinkedList(first);
            break;
        case 9:
            merging(first,first1);
            break;

        }

    }while(choice!=10);
    printf("DROP DOWN MENU COMPLETED!");
    return 0;

}
