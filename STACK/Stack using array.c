#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *s;
};
void push(struct stack *ST,int n);
void pop(struct stack *ST);
void stackTop(struct stack ST);
void isEmpty(struct stack ST);
void isFull(struct stack ST);
void peek(struct stack ST,int pos);
void display(struct stack ST);
void display(struct stack ST)
{
    int i;
    for(i=ST.top;i>=0.;i--)
    {
        printf("%d ",ST.s[i]);
    }
    printf("\n");
}
void push(struct stack *ST,int n)
{
    if(ST->top==ST->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
    ST->top++;
    ST->s[ST->top]=n;
    }
}
void pop(struct stack *ST)
{
    int x;
    if(ST->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x=ST->s[ST->top];
        ST->top--;
        printf("The element %d is removed\n",x);
    }
}
void stackTop(struct stack ST)
{
    int x;
    if(ST.top==-1)
    {
        printf("No top element is present\n");
    }
    else
    {
    x=ST.s[ST.top];
    printf("The top element present in the stack is %d\n",x);
    }
}
void isEmpty(struct stack ST)
{
    if(ST.top==-1)
    {
        printf("The Stack Is Empty\n");
    }
    else
    {
        printf("The Stack Is Not Empty\n");
    }
}
void isFull(struct stack ST)
{
    if(ST.top==ST.size-1)
    {
        printf("The Stack Is Full\n");
    }
    else
    {
        printf("The Stack Is Not Full\n");void isFull(struct stack ST);


    }
}
void peek(struct stack ST,int pos)
{
    int x;
    if((pos <=0 && pos >ST.top) || ST.top==-1)
    {
        printf("Invalid Position\n");
    }
    else
    {
       x=ST.s[ST.top+1-pos];
       printf("The Element present at position %d is %d\n",pos,x);
    }
}
int main()
{
    struct stack st;
    int choice,position,number;
    printf("Enter the size of the stack:");
    scanf("%d",&st.size);
    st.s=(int*)malloc(sizeof(int)*st.size);
    st.top=-1;
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Stack Top\n5.Stack is Empty?\n6.stack is Full\n7.Display\n8.QUIT\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number:");
            scanf("%d",&number);
            push(&st,number);
            break;
        case 2:
            pop(&st);
            break;
        case 3:
            printf("Enter the position:");
            scanf("%d",&position);
            peek(st,position);
            break;
        case 4:
            stackTop(st);
            break;
        case 5:
            isEmpty(st);
            break;
        case 6:
            isFull(st);
            break;
        case 7:
            display(st);
            break;

        }
    }while(choice!=8);
    return 0;
}
