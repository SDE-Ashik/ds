// linear queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front = 0, *rear = 0, *temp, *new;

void enqueue(int x)
{
    
    new = (struct queue *)malloc(sizeof(struct queue));
    new->data = x;
    new->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = new;
    }
    else
    {
        rear->next=new;
        rear = new;
        new->next = 0;
    }
}
// deletion
void dequeue()
{
    if (front == 0 && rear == 0)
    {
        printf("\n underflow occured\n");
    }
    else if (front == rear)
    {
        printf("\ndeleted element is%d\n", front->data);
        front = rear = 0;
    }
    else
    {
        temp = front;
        printf("\ndeleted elements is %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}
// display
void display()
{
    if (rear == 0 && front == 0)
    {
        printf("\n queue is empty\n");
    }
    else
    {
        temp = front;
        printf("\nelements in queue are:\n");
        while (temp != 0)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch,value;

    printf("\n\t\t\tQUEUE\n");
    do
    {
        printf("\n\noperations in linear queue are given below:\n\t\t\t1.INSERTION\n\t\t\t2.DELETION\n\t\t\t3.DISPLAY\n\t\t\t4.EXIT\n");
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            
            printf("enter the data :");
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEXIT\n");
            break;
        default:
            printf("\n INVALID CHOICE \n");
            break;
        }

    } while (ch!=4);
}
