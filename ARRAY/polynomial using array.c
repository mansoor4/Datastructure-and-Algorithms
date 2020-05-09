#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct Term
{
    int coef;
    int expo;
};
struct Poly
{
    int n;
    struct Term *t;
};
void create(struct Poly*p);
struct Poly* solve(struct Poly*p1,struct Poly*p2);
void display(struct Poly*p);
int solvePoly(struct Poly*p,int x);
void create(struct Poly*p)
{
    printf("Enter the number of terms:");
    scanf("%d",&p->n);
    p->t=(struct Term*)malloc((p->n)*sizeof(struct Term));
    for(int i=0;i<p->n;i++)
    {
        printf("Enter data of term %d:",i+1);
        scanf("%d%d",&p->t[i].coef,&p->t[i].expo);
    }
}
struct Poly* solve(struct Poly*p1,struct Poly*p2)
{
    struct Poly *p3;
    p3=(struct Poly*)malloc(sizeof(struct Poly));
    p3->t=(struct Term*)malloc((p1->n+p2->n)*sizeof(struct Term));
    int i=0,j=0,k=0;
    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].expo>p2->t[j].expo)
        {
            p3->t[k++]=p1->t[i++];
        }
        else if(p1->t[i].expo<p2->t[j].expo)
        {
            p3->t[k++]=p2->t[j++];
        }
        else
        {
            p3->t[k].expo=p1->t[i].expo;
            p3->t[k].coef=p1->t[i].coef+p2->t[j].coef;
            k++;
            i++;
            j++;
        }
    }
    while(i<p1->n)
    {
        p3->t[k++]=p1->t[i++];
    }
    while(j<p2->n)
    {
        p3->t[k++]=p2->t[j++];
    }
    p3->n=k;
    return p3;
}
void display(struct Poly*p)
{
    int i;
    for(i=0;i<p->n;i++)
    {
     printf("%dX^%d+",p->t[i].coef,p->t[i].expo);
    }
}
int solvePoly(struct Poly*p,int x)
{
    int i,sum=0;
    for(i=0;i<p->n;i++)
    {
        sum+=p->t[i].coef*(pow(x,p->t[i].expo));
    }
    return sum;
}
int main()
{
    struct Poly p1,p2,*p3;
    int x;
    create(&p1);
    create(&p2);
   p3=solve(&p1,&p2);
   display(p3);
   printf("\nEnter the value X:");
   scanf("%d",&x);
   printf("Answer of poly is %d",solvePoly(p3,x));
  return 0;
}
