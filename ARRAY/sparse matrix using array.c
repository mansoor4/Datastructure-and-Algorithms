#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Sparse
{
    int data;
    int row;
    int col;
};
int main()
{
    struct Sparse *s1,*s2,*s3;
    int n1,n2,i,j,k,mRow,mCol;
    printf("Enter the rows and columns of both sparse matrix:");
    scanf("%d%d",&mRow,&mCol);
    printf("Enter the number of elements of sparse1:");
    scanf("%d",&n1);
    s1=(struct Sparse*)malloc(n1*sizeof(struct Sparse));
    printf("Enter the  elements and its row an column\n");
    for( i=0;i<n1;i++)
    {
        scanf("%d%d%d",&s1[i].data,&s1[i].row,&s1[i].col);
    }
     printf("Enter the number of elements of sparse2:");
    scanf("%d",&n2);
    s2=(struct Sparse*)malloc(n2*sizeof(struct Sparse));
    printf("Enter the  elements and its row an column\n");
    for( i=0;i<n2;i++)
    {
        scanf("%d%d%d",&s2[i].data,&s2[i].row,&s2[i].col);
    }
    s3=(struct Sparse*)malloc((n1+n2)*sizeof(struct Sparse));
    i=j=k=0;
    while(i<n1 && j<n2)
    {
        if(s1[i].row<s2[j].row)
        {
            s3[k++]=s1[i++];
        }
       else if(s1[i].row>s2[j].row)
        {
            s3[k++]=s2[j++];
        }
        else
        {
            if(s1[i].col<s2[j].col)
            {
                s3[k++]=s1[i++];
            }
            else if(s1[i].col>s2[j].col)
            {
                s3[k++]=s2[j++];
            }
            else
            {

                s3[k].row=s1[i].row;
                s3[k].col=s1[i].col;
                s3[k].data=s1[i].data+s2[j].data;
                i++;
                j++;
                k++;
            }

        }
    }
    while(i<n1)
    {
        s3[k++]=s1[i++];
    }
    while(j<n2)
    {
        s3[k++]=s2[j++];
    }
    k=0;
    for(i=0;i<mRow;i++)
    {
        for(j=0;j<mCol;j++)
        {
            if(i==s3[k].row && j==s3[k].col)
            {
                printf("%d ",s3[k].data);
                k++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
