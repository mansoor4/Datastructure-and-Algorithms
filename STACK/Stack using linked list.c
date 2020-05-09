#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;

}*first=NULL,*top=NULL;
int size;
void push(struct Node*p,int n);
void pop(struct Node*p);
void stackTop();
void isEmpty();
void display(struct Node *p);
void peek(struct Node*p,int pos);
void push(struct Node*p,int n)
{
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=n;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        top=t;
        size++;
    }
    else
    {
        top->next=t;
        top=t;
        size++;
    }

}
void pop(struct Node*p)
{
    int x;
    if(top==NULL)
    {
        printf("No  Element Is Present In Stack\n");
    }
    else
    {
    while(p->next!=top && p->next!=NULL)
    {
        p=p->next;
    }
    if(p->next==NULL)
    {
        x=top->data;
        free(top);
        top=NULL;
        size--;
        printf("Element %d is removed\n",x);
    }
    else
    {
    x=top->data;
    free(top);
    p->next=NULL;
    top=p;
    size--;
    printf("Element %d is removed\n",x);
    }
}
}
void stackTop()
{
    int x;
    if(top==NULL)
    {
        printf("No Top Element Is Present\n");
    }
    else
    {
        x=top->data;
        printf("The element at the top is %d\n",x);
    }
}
void isEmpty()
{
    if(top==NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }
}
void display(struct Node *p)
{
    if(p!=NULL)
    {
        display(p->next);
        printf("%d ",p->data);
        if(p==first)
        {
            printf("\n");
        }
    }
}
void peek(struct Node*p,int pos)
{
    int i,x;
    if(top==NULL)
    {
       printf("No element is present\n");
    }
    else
    {
        if(pos>size)
        {
            printf("Invalid position\n");
        }
        else
        {
            for(i=0;i<size-pos;i++)
            {
                p=p->next;
            }
            x=p->data;
            printf("The element present at position %d is %d\n",pos,x);
        }

    }
}
int main()
{
    int number,choice,position;
 do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Stack Top\n5.Stack is Empty?\n6.Display\n7.QUIT\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number:");
            scanf("%d",&number);
            push(first,number);
            break;
        case 2:
            pop(first);
            break;
       case 3:
            printf("Enter the position:");
            scanf("%d",&position);
            peek(first,position);
            break;
        case 4:
            stackTop();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            display(first);
            break;
        }
    }while(choice!=7);
    return 0;

}
