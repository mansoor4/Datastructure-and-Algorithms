#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *que;
};
// Declaration.
void enqueue(struct queue *Q,int n);
void dequeue(struct queue *Q);
void isEmpty(struct queue Q);
void isFull(struct queue Q);
void first (struct queue Q);
void last (struct queue Q);
void display(struct queue Q);
//********************************

// Definition.
void enqueue(struct queue *Q,int n)
{
    if(((Q->rear+1)%Q->size)==Q->front)
    {
        printf("The queue is full\n");
    }
    else
    {
    Q->rear=(Q->rear+1)%Q->size;
    Q->que[Q->rear]=n;
    }
}
void dequeue(struct queue *Q)
{
    if(Q->front==Q->rear)
    {
        printf("The queue is empty\n");
        return;
    }
    else
    {
    Q->front=(Q->front+1)%Q->size;
    printf("The %d is deleted\n",Q->que[Q->front]);
    }
}
void isEmpty(struct queue Q)
{
    if(Q.front==Q.rear)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }
}
void isFull(struct queue Q)
{
    if(((Q.rear+1)%Q.size)==Q.front)
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
}
void first (struct queue Q)
{
    printf("The first element in the queue is %d\n",Q.que[(Q.front+1)%Q.size]);
}
void last (struct queue Q)
{
    printf("The last element in the queue is %d\n",Q.que[Q.rear]);
}
void display(struct queue Q)
{
    int sliding=(Q.front);
    if(Q.front==Q.rear)
    {
        printf("The queue is empty\n");
        return ;
    }
    while(sliding!=Q.rear)
    {
        sliding=(sliding+1)%Q.size;
        printf("%d ",Q.que[sliding]);
    }
    printf("\n");
}
int main()
{
    struct queue q;
    int choice,number;
    printf("Enter the size of the Queue:");
    scanf("%d",&q.size);
    q.que=(int*)malloc(sizeof(int)*q.size);
    q.front=0;
    q.rear=0;
    do
    {
        printf("1.Insert\n2.Delete\n3.Queue is empty?\n4.Queue is full?\n5.First element in queue\n6.Last element in queue\n7.Display\n8.QUIT\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number to insert:");
            scanf("%d",&number);
            enqueue(&q,number);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            isEmpty(q);
            break;
        case 4:
            isFull(q);
            break;
        case 5:
            first(q);
            break;
        case 6:
            last(q);
            break;
        case 7:
            display(q);
            break;
        }
    }while(choice!=8);
    return 0;
}
