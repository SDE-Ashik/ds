#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

struct stack
{
int data;
struct stack *next;
};
struct stack *temp,*newnode,*head=0;
int top=0,size;
void main()
{
printf("\nenter size:\n");
scanf("%d",&size);
int ch;

	do{
printf("\n menu \n 1.push \n 2.pop\n 3. display \n 4. exit \n ");
printf("enter your choice\n");
scanf("%d",&ch);
	switch(ch){
case 1: 
	push();
	break;
case 2:
	pop();
	break;
case 3: display();
break;
case 4:
printf("\n exit\n");
break;
default:
printf("\ninvalid choice \n");
}}while(ch!=4);

}

void push()
{
if(top==size)
{printf("\n stack overflow\n");}
else{
printf("\nenter a data:");
newnode = (struct stack*) malloc (sizeof(struct stack));
scanf("%d",&newnode->data);
newnode->next= temp;
temp = head;
head= newnode;
newnode->next =temp;;
top++;
}
}

void pop()
{
if(top==0)
{printf("\n underflow occured\n");}
else{
temp = head;
printf("\n poped data is %d",head->data);
head = temp->next;

free(temp);
top--;


}

}
void display()
{

if (head ==0)
{printf("\n no data found \n");}
else{
temp=head;
printf("\nvalues in stack are\n");
while (temp!=0)

{
printf("%d-->",temp->data);
temp= temp->next;
}
}
}
