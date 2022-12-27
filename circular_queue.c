// circular queue using array...

#include<stdio.h>
int size ,queue[100],front=-1,rear=-1;
void enqueue()
{
if(rear==-1 && front==-1)
{
     rear=front=0;
    printf("\nenter the data:");
    scanf("%d",&queue[rear]);
   
}
else if ((rear+1)%size==front)
{
    printf("\noverflow occured\n");
}
else
{
    rear=(rear+1)%size;
    printf("\nenter the data:");
    scanf("%d",&queue[rear]);
}

}
void dequeue()
{
    if (rear==-1 && front==-1)
    {
        printf("\nunderflow occured\n");
    }
    else if (rear==front)
    {
        printf("\n deleted element is %d\n",queue[front]);
        rear=-1;
        front=-1;
    }
    else
    {
        printf("\n deleted element is %d\n",queue[front]);
        front=(front+1)%size;
    }
    
    
}
void display()
{
    int i=front;
    if(rear==-1)
    {
        printf("\n Queue is empty\n");
    }
    else
    {
        printf("\n queue elements are:\n ");
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%size;
        }
        printf("%d",queue[rear]);
    }
    
}
int main()
{
    int ch;
    printf("\n \t\t\tcircular queue\n");
    printf("\nenter the size:");
    scanf("%d",&size);
    do
    {
        printf("\ncircular queue opertions are given below:\n\t\t\t1.INSERTION\n\t\t\t2.DELETION\n\t\t\t3.DISPLAY\n\t\t\t4.EXIT");
        printf("\n\nselect any operation:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
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
        printf("\n invalid choice...try again \n");
            break;
        }
    } while (ch!=4);
    

}
