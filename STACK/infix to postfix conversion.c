#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *s;
};
// Declaration.
char* infixToPostfix(struct stack ST,char *S);
int Operator(char c);
int pre(char c);
//****************************
void push(struct stack *ST,char n);
char pop(struct stack *ST);
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
char pop(struct stack *ST)
{
    char c=' ';
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
int pre(char c)
{
    if(c=='+'|| c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    return 0;
}
char* infixToPostfix(struct stack ST,char *EXP)
{
    char *postfix=(char*)malloc(sizeof(char)*strlen(EXP));
    int i,k=0;
    for(i=0;i<strlen(EXP);i++)
    {
        if(Operator(EXP[i]))
        {
            if(isEmpty(ST))
            {
                push(&ST,EXP[i]);
            }
            else
            {
                if(pre(EXP[i])>pre(ST.s[ST.top]))
                {
                    push(&ST,EXP[i]);
                }
                else
                {
                    while(pre(EXP[i])<=pre(ST.s[ST.top])&& !isEmpty(ST))
                    {
                       postfix[k++]= pop(&ST);
                    }
                    push(&ST,EXP[i]);
                }
            }
        }
        else
        {
            postfix[k++]=EXP[i];
        }
    }
    while(!isEmpty(ST))
    {
        postfix[k++]=pop(&ST);
    }
    postfix[k]='\0';
    return postfix;
}
int main()
{
 struct stack st;
 char *POSTFIX;
 int i;
 char exp[]="a+b*c-d";
 st.size=strlen(exp);
 st.s=(char*)malloc(sizeof(char)*st.size);
 st.top=-1;
 POSTFIX=infixToPostfix(st,exp);
 for(i=0;i<strlen(exp);i++)
 {
     printf("%c ",POSTFIX[i]);
 }
 return 0;
}
