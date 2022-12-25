#include<stdio.h>
int queue[25],front=-1,rear=-1,size;
// insertion 
void enque()
{
    if(rear>=size-1)
    {
        printf("\n overflow occured\n");
    }
    else if (rear==-1 && front==-1)
    {
        front=0;
        rear=0;
        printf("\ninsert an element in the queue:");
        scanf("%d",&queue[rear]);
    }
    else
    {
        rear++;
        printf("\n insert an element in the queue:");
        scanf("%d",&queue[rear]);
    }
    
    

}

// deletion 
void dequeue()
{
    if(rear==-1  )
    {
        printf("\nunderflow occured\n");
    }
    else if (rear==front)
    {
        printf("deleted element is %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("deleted element is %d\n",queue[front]);
        front++;
    }
    
}

// display
void display()
{int i;
    if(rear==-1 )
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("\n Display elements in a queue:\n");
        for ( i = front; i <= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");
        
        
    }
    
}
void main()
{
    int choice;
    printf("\nenter the size of a queue:");
    scanf("%d",&size);
    printf("\n\t\t\tQUEUE\n");
    do
    {
        /* code */
  
    
    printf("operations in a queue are\n\t\t\t1.INSERTION\n\t\t\t2.DELETION\n\t\t\t3.DISPLAY\n\t\t\t4.EXIT");
    printf("\n enter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        enque();
        break;
    case 2:
        dequeue();
        break;
     case 3:
        display();
        break;
     case 4:
        printf("\n EXIT\n");
        break;
    default:
        printf("\ninvalid choice\n");
        break;
    }
      } while (choice!=4);
}
