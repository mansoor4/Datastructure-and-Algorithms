#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct array
{
    int *a;
    int size;
    int length;

};
void add(struct array *s1,int n);
void display(struct array s1);
void Delete(struct array *s1,int index1);
void insert(struct array *s1,int n,int index);
int sum(struct array s1);
void leftRotation(struct array *s1,int lr1);
void rightRotation(struct array *s1,int rr1);
void add(struct array *s1,int n)
{
    if(s1->length<=s1->size)
    {
    s1->a[s1->length]=n;
    s1->length++;
    }
    else
    {
        printf("Element should not added\n");
    }
}
void display(struct array s1)
{
    int i;
    for(i=0;i<s1.length;i++)
    {
        printf("%d ",s1.a[i]);
    }
    printf("\n");

}
void Delete(struct array *s1,int index1)
{
    if(index1<s1->length)
    {
    int i;
    for(i=index1;i<s1->length-1;i++)
    {
        s1->a[i]=s1->a[i+1];
    }
    s1->length--;
    }
    else
    {
        printf("Invalid index\n");
    }
}
void insert(struct array *s1,int n,int index)
{
    int i;
    if(index<s1->length)
    {
    for(i=s1->length;i>index;i--)
    {
        s1->a[i]=s1->a[i-1];
    }
    s1->a[index]=n;
    s1->length++;
    }
    else{
        printf("Invalid index\n");
    }
}
int sum(struct array s1)
{
    int sum=0,i;
    for(i=0;i<s1.length;i++)
    {
        sum+=s1.a[i];
    }
    return(sum);
}
void leftRotation(struct array *s1,int lr1)
{
    int i,x,j;
    for(j=1;j<=lr1;j++)
    {
    x=s1->a[0];
    for(i=0;i<s1->length-1;i++)
    {
        s1->a[i]=s1->a[i+1];
    }
    s1->a[i]=x;
    }
}
void rightRotation(struct array *s1,int rr1)
{
    int i,j,x;
    for(j=1;j<=rr1;j++)
    {
        x=s1->a[s1->length-1];
        for(i=s1->length-1;i>0;i--)
        {
            s1->a[i]=s1->a[i-1];
        }
        s1->a[0]=x;
    }
}
int main()
{
    struct array s;
    int c,num,index,lr,rr;
    printf("Enter the size of the array\n");
    scanf("%d",&s.size);
    s.a=(int*)malloc(s.size*sizeof(int));
    s.length=0;
    while(c!=8)
    {
         printf("1.Add\n2.Display\n3.Delete\n4.Insert\n5.Sum\n6.Left Rotate\n7.Right Rotate\n8.QUIT\n");
        printf("Enter the task:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter the number:");
            scanf("%d",&num);
            add(&s,num);
            break;
        case 2:
            display(s);
            break;
        case 3:
            printf("enter the index:");
            scanf("%d",&index);
            Delete(&s,index);
            break;
        case 4:
            printf("Enter the number and its index:");
            scanf("%d%d",&num,&index);
            insert(&s,num,index);
            break;
        case 5:
            printf("The sum of the array is %d\n",sum(s));
            break;
        case 6:
            printf("Number of rotations:");
            scanf("%d",&lr);
            leftRotation(&s,lr);
            break;
        case 7:
            printf("Number of rotations:");
            scanf("%d",&rr);
            rightRotation(&s,rr);
            break;
        default:
            if(c!=8)
            {
                printf("Invalid operation");
            }
        }

    }
    printf("THANKS FOR PLAYING");
    return 0;

}
