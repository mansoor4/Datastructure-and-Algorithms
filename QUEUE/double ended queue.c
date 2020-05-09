#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct queue
{
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;
//  DECLARATION.
void enqueue(int n);
void frontDequeue();
void rearDequeue();
void isEmpty();
void isFull();
void first();
void last();
void display();
//DEFINITION.
void enqueue(int n)
{
    struct queue *t;
    t=(struct queue*)malloc(sizeof(struct queue));
    if(t==NULL)
    {
        printf("The queue is full\n");
    }
    else
    {
        t->data=n;
        t->next=NULL;
        if(rear==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
void frontDequeue()
{
    int x;
    struct queue *follow=NULL;
    if(front==NULL && rear==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        follow=front;
        if(front==rear)
        {
            x=front->data;
            front=rear=NULL;
            free(follow);
            printf("%d is deleted\n",x);
        }
        else
        {
            x=front->data;
            front=front->next;
            free(follow);
            printf("%d is deleted\n",x);
        }
    }
}
void rearDequeue()
{
    int x;
    struct queue *follow=NULL;
    if(front==NULL && rear==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        follow=front;
        if(front==rear)
        {
            follow=rear;
            x=rear->data;
            front=rear=NULL;
            free(follow);
            printf("%d is deleted\n",x);
        }
        else
        {
            while(follow->next!=rear)
            {
                follow=follow->next;
            }
            x=rear->data;
            rear=follow;
            follow=follow->next;
            free(follow);
            rear->next=NULL;
            printf("%d is deleted\n",x);
        }
    }
}
void isEmpty()
{
    if(rear==NULL && front==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The queue is not empty\n");
    }
}
void isFull()
{
    struct queue*t;
    t=(struct queue*)malloc(sizeof(struct queue));
    if(t==NULL)
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("The queue is not full\n");
    }
}
void first()
{
    if(rear==NULL && front==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The first element in the queue is %d\n",front->data);
    }
}
void last()
{
     if(rear==NULL && front==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The last element in the queue is %d\n",rear->data);
    }
}
void display()
{
    struct queue *follow=front;
     if(rear==NULL && front==NULL)
    {
        printf("The queue is empty do not display\n");
    }
    else
    {
  while(follow!=NULL)
  {
      printf("%d ",follow->data);
      follow=follow->next;
  }
    printf("\n");
}
}
int main()
{
    int choice,number;
     do
    {
        printf("1.Insert\n2.Delete from front\n3.Queue is empty?\n4.Queue is full?\n5.First element in queue\n6.Last element in queue\n7.Display\n8.Delete from rear\n9.QUIT\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number to insert:");
            scanf("%d",&number);
            enqueue(number);
            break;
        case 2:
            frontDequeue();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            first();
            break;
        case 6:
            last();
            break;
        case 7:
            display();
            break;
        case 8:
            rearDequeue();
            break;
        }
    }while(choice!=9);
    return 0;
}

