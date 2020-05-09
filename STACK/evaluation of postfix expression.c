#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack
{
    int size;
    int top;
    int *s;
};
// Declaration.
int evaluationPostfix(struct stack ST,char *postfix);
int Operator(char c);
//****************************
void push(struct stack *ST,int n);
int pop(struct stack *ST);
int  isEmpty(struct stack ST);
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
int pop(struct stack *ST)
{
    int c=' ';
    if(ST->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        c=ST->s[ST->top];
        ST->top--;
    }
    return c;
}
int isEmpty(struct stack ST)
{
    if(ST.top==-1)
    {
       return 1;
    }
    else
    {
        return 0;
    }
}
// Definition.
int Operator(char c)
{
    if(c=='+' || c=='-'|| c=='/' || c=='*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int evaluationPostfix(struct stack ST,char *postfix)
{
    int i,x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(!Operator(postfix[i]))
        {
            push(&ST,postfix[i]-48);
        }
        else
        {
            x2=pop(&ST);
            x1=pop(&ST);
            switch(postfix[i])
            {
        case '+':
            r=x1+x2;
            push(&ST,r);
            break;
        case '-':
            r=x1-x2;
            push(&ST,r);
            break;
        case '*':
            r=x1*x2;
            push(&ST,r);
            break;
        case '/':
            r=x1/x2;
            push(&ST,r);
            break;

            }
        }
    }
    return pop(&ST);
}
int main()
{
 struct stack st;
 int RESULT;;
 char POSTFIX[]="54*62/+4-8+";
 st.size=strlen(POSTFIX);
 st.s=(int*)malloc(sizeof(int)*st.size);
 st.top=-1;
 RESULT=evaluationPostfix(st,POSTFIX);
 printf("The answer for the postfix expression is %d",RESULT);
  return 0;
}
