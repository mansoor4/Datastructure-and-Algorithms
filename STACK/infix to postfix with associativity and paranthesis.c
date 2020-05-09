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
char* infixToPostfix(struct stack ST,char *EXP);
int Operator(char c);
int OutStackpre(char c);
int InStackpre(char c);
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
    if(c=='+' || c=='-'|| c=='/' || c=='*' || c=='(' || c=='^' || c==')' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int OutStackpre(char c)
{
    if(c=='+'|| c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 3;
    }
    else if(c=='^')
    {
        return 6;
    }
    else if(c=='(')
    {
        return 7;
    }
    return 0;
}
int InStackpre(char c)
{
    if(c=='+'|| c=='-')
    {
        return 2;
    }
    else if(c=='*' || c=='/')
    {
        return 4;
    }
    else if(c=='^')
    {
        return 5;
    }
    return 0;
}
char* infixToPostfix(struct stack ST,char *EXP)
{
    char *postfix=(char*)malloc(sizeof(char)*(strlen(EXP)+1));
    int i=0,j=0;
    while(EXP[i]!='\0')
    {
        if(Operator(EXP[i]))
        {
            if(isEmpty(ST))
            {
                push(&ST,EXP[i++]);
            }
            else
            {
                if(OutStackpre(EXP[i])>InStackpre(ST.s[ST.top]))
                {
                    push(&ST,EXP[i++]);
                }
                else if(OutStackpre(EXP[i])<InStackpre(ST.s[ST.top]))
                {
                    postfix[j++]=pop(&ST);
                }
                else
                {
                    pop(&ST);
                    i++;
                }
            }
        }
        else
        {
            postfix[j++]=EXP[i++];
        }
    }
    while(!isEmpty(ST))
    {
        postfix[j++]=pop(&ST);
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
 struct stack st;
 char *POSTFIX;
 int i;
 char exp[]="a^b^c-d*f*g";
 st.size=strlen(exp);
 st.s=(char*)malloc(sizeof(char)*st.size);
 st.top=-1;
 POSTFIX=infixToPostfix(st,exp);
 for(i=0;i<=strlen(exp);i++)
 {
     printf("%c ",POSTFIX[i]);
 }
 return 0;
}
