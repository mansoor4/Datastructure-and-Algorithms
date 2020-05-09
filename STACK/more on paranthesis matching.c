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
/// PARANTHESIS MATCHING DEFINITION.
int isBalance(struct stack ST,char *EXP)
{
    int i;
    for(i=0;i<strlen(EXP);i++)
    {
        if((EXP[i]=='(') ||(EXP[i]=='{')||(EXP[i]=='['))
        {
            push(&ST,EXP[i]);
        }
        else if((EXP[i]==')')||( EXP[i]==']')||(EXP[i]=='}'))
        {
            if(isEmpty(ST))
            {
                return 0;
            }
            else
            {
                char x=pop(&ST);
               if(x<50 && ((EXP[i]-x)!=1))
               {
                return 0;
               }
               else if(x>50 && x<100 && ((EXP[i]-x)!=2))
               {
                   return 0;
               }
               else if(x>100 &&x<130 && ((EXP[i]-x)!=2))
               {
                   return 0;
               }
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
