#include <stdio.h>
struct queue
{
int a[5];
int front, rear;
} q;
void insert()
{
int p,x;
p=(q.rear+1)%5;
if (p==q.front)
printf("Circular Queue Overflow\n"); 
else
{
printf("Enter element to be inserted in circular queue:");
scanf("%d", &x);
q.rear++;
q.a[p]=x;
q.rear=p;
if (q.front==-1)
q.front=0;
}
}
void delete1()
{
if (q.front == -1)
printf("Circular Queue Underflow\n"); 
else
{
printf("Element deleted is %d \n",q.a[q.front]); 
if(q.front==q.rear)
q.front = q.rear = -1; 
else
q.front=(q.front+1)%5;
}
}
void display()
{
if (q.front == -1)
printf("Circular Queue Underflow\n"); 
else
{
printf("Elements of circular queue are \n"); 
for(int i = q.front; i!= q.rear; i=(i+1)%5)
{
printf("%d\n",q.a[i]);
}
printf("%d\n",q.a[q.rear]);
}
}
void destory()
{
q.front=q.rear=-1;
printf("Circular Queue is destoryed \n");
}
void main()
{
int ch;
q.front=q.rear = -1;
do
{
printf("MENU\n 1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.DESTORY\n 5.EXIT\n");
printf("Enter a Choice:");
scanf("%d", &ch);
switch(ch)
{
case 1: insert();
break;
case 2: delete1();
break;
case 3: display();
break;
case 4: destory();
break;
case 5: break;
default : printf("Entered a wrong choice");
}
}
while(ch!=5);
}
