#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Queue
{
    int data;
    struct Queue *next;
}*top1=NULL,*top2=NULL;
//  STACK DECLARATION.
void pushs1(int n);
void pushs2(int n);
int pops1();
int pops2();
int emptys1();
int emptys2();
// ****************************

// QUEUE DECLARATION
void enqueue(int n);
void dequeue();
void display1();
void display2();
//*******************************8

//DEFINITION.
void pushs1(int n)
{
    struct Queue *t;
    t=(struct Queue*)malloc(sizeof(struct Queue));
    t->data=n;
    if(top1==NULL)
    {
        top1=t;
        top1->next=NULL;
    }
    else
    {
        t->next=top1;
        top1=t;
    }
}
void pushs2(int n)
{
    struct Queue *t;
    t=(struct Queue*)malloc(sizeof(struct Queue));
    t->data=n;
    if(top2==NULL)
    {
        top2=t;
        top2->next=NULL;
    }
    else
    {
        t->next=top2;
        top2=t;
    }
}
int pops2()
{
    int x;
    struct Queue *follow=NULL;
    if(emptys2())
    {
        return 0;
    }
    else
    {
        x=top2->data;
        follow=top2;
        top2=top2->next;
        free(follow);
        return x;
    }
}
int pops1()
{
    int x;
    struct Queue *follow=NULL;
    if(emptys1())
    {
        return 0;
    }
    else
    {
        x=top1->data;
        follow=top1;
        top1=top1->next;
        free(follow);
        return x;
    }
}
int emptys1()
{
    if(top1==NULL)
    {
        return 1;
    }
    return 0;
}
int emptys2()
{
    if(top2==NULL)
    {
        return 1;
    }
    return 0;
}
// ***************************************************************************************************************************************************

// QUEUE DEFINITION.
void enqueue(int n)
{
        pushs1(n);
}
void dequeue()
{
    int x=0;
     if(emptys1() && emptys2())
    {
        printf("Queue is empty\n");
    }
    else if(emptys2())
    {
        while(!emptys1())
        {
            pushs2(pops1());
        }
        x=pops2();
        printf("%d is deleted\n",x);
    }
    else
    {
        x=pops2();
        printf("%d is deleted\n",x);
    }
}
void display1(struct Queue *follow)
{
    if(follow!=NULL)
    {
        display1(follow->next);
        printf("%d ",follow->data);
        if(follow==top1)
        {
            printf("\n");
        }
    }
}
void display2(struct Queue *follow)
{
    if(!emptys2())
    {
    while(follow!=NULL)
    {
        printf("%d ",follow->data);
        follow=follow->next;
    }
    if(emptys1())
    printf("\n");
    }
}
//****************************************************************************************************************************************************
int main()
{
 int number,choice;
 do
 {
     printf("1.Insert\n2.Delete\n3.Display\n4.QUIT\n");
     printf("Enter the choice:");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        printf("Enter the number to insert:");
        scanf("%d",&number);
        enqueue(number);
        break;
     case 2:
        dequeue();
        break;
     case 3:
        display2(top2);
        display1(top1);
        break;
     }
 }while(choice!=4);
 return 0;
}
