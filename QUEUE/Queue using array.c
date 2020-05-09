#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// DRAWBACK OF SIMPLE QUEUE-
// If the queue is full and some space is empty it cannot insert more element.
// These drawback is overcome by circular queue.
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
    if(Q->rear==(Q->size-1))
    {
        printf("The queue is full\n");
    }
    else
    {
    Q->rear++;
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
    Q->front++;
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
    if(Q.rear==(Q.size-1))
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
    printf("The first element in the queue is %d\n",Q.que[Q.front+1]);
}
void last (struct queue Q)
{
    printf("The last element in the queue is %d\n",Q.que[Q.rear]);
}
void display(struct queue Q)
{
    int i;
    if(Q.front==Q.rear)
    {
        printf("The queue is empty\n");
        return ;
    }
    for(i=Q.front+1;i<=Q.rear;i++)
    {
        printf("%d ",Q.que[i]);
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
    q.front=-1;
    q.rear=-1;
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
