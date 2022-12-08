#include <stdio.h>
int push();
int pop();
int display();

int top = -1, stack[100], n;
int main()
{
    int choice;
    printf("\t \t \t  STACK\n");
    printf("enter the size of a stack:\t");
    scanf("%d", &n);
    do
    {
        printf("\noperations in stack are\n \t\t\t 1.inseration \n\t\t\t 2.deletion \n\t\t\t 3.Display \n\t\t\t4.EXIT");
        printf("\nselect any operation :\n \t \t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            // remove();
            printf("THANK YOU ");
            break;
        default:
            printf("\ninvalid option.. try again\n");
        }

    } while (choice != 4);
}

int push()
{
    int num;
    if (top == n - 1)
    {

        printf("\noverflow occured\npress any key ");
    }
    else

        printf("enter  a value to be pushed:\n\t\t");
    scanf("%d", &num);

    top++;
    stack[top] = num;
}

int pop()
{

    if (top == -1)
    {
        printf("underflow occured\n");
    }
    else
    {
        printf("The popped elements is , %d", stack[top]);

        top--;
    }
}

int display()
{

    if (top == -1)
    {
        printf("stack is empty....\n");
    }
    else
    {
        printf("Displaying elements in the stack\n\t\t\t");
        for (int i = top; i >= 0; i--)

        {
            printf("%d\n", stack[i]);
        }
    }
}
