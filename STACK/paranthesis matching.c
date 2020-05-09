#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack
{
    int size;
    int top;
    char *s;
};
// PRANTHESIS MATCHING DECLARATION.
int isBalance(struct stack ST,char *EXP);
//***************************************
void push(struct stack *ST,char n);
void pop(struct stack *ST);
int  isEmpty(struct stack ST);
void push(struct stack *ST,char n)
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
    if(ST->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        ST->top--;
    }
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
/// PARANTHESIS MATCHING DEFINITION.
int isBalance(struct stack ST,char *EXP)
{
    int i;
    for(i=0;i<strlen(EXP);i++)
    {
        if(EXP[i]=='(')
        {
            push(&ST,EXP[i]);
        }
        else if(EXP[i]==')')
        {
            if(isEmpty(ST))
            {
                return 0;
            }
            else
            {
                pop(&ST);
            }
        }
    }
    if(isEmpty(ST))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    char exp[]="((a+b)*(c-d))";
    struct stack st;
    st.size=strlen(exp);
    st.s=(char*)malloc(sizeof(char)*st.size);
    st.top=-1;
   printf("The given expression is balanced ", isBalance(st,exp)?printf("True-"):printf("False-"));
   return 0;
}
