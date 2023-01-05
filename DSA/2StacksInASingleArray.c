#include <stdio.h>
struct stack
{
int a[20];
int top1, top2;
} s;
void push1()
{
int x;
if (s.top1+1==s.top2)
printf("Stack 1 Overflow\n");
else
{
printf("Enter element to push in Stack 1:");
scanf("%d", &x);
s.top1++;
s.a[s.top1]=x;
}
}
void push2()
{
int x;
if (s.top1+1==s.top2)
printf("Stack 2 Overflow\n");
else
{
printf("Enter element to push in Stack 2:");
scanf("%d", &x);
s.top2--;
s.a[s.top2]=x;
}
}
void pop1()
{
if (s.top1 == -1)
printf("Stack 1 Underflow\n");
else
{
printf("Element popped in the Stack 1 is %d \n",s.a[s.top1]); 
s.top1--;
}
}
void pop2()
{
if (s.top2 == 20)
printf("Stack 2 Underflow\n");
else
{
printf("Element popped in the Stack 2 is %d \n",s.a[s.top2]);
s.top2++;
}
}
void display1()
{
if (s.top1==-1)
printf("Stack 1 Underflow\n");
else
{
printf("Elements of the Stack 1 are \n");
for(int i = 0 ; i<= s.top1; i++)
printf("%d\n",s.a[i]);
}
}
void display2()
{
if (s.top2==20)
printf("Stack 2 Underflow\n");
else
{
printf("Elements of the Stack 2 are \n");
for(int i=19; i>=s.top2; i--)
printf("%d\n",s.a[i]);
}
}
void destory1()
{
s.top1 = -1;
printf("Stack 1 Destoryed \n");
}
void destory2()
{
s.top2 =20;
printf("Stack 2 Destoryed \n");
}
void main()
{
s.top1=-1; 
s.top2=20;
int ch;
do
{
printf("MENU\n 1.PUSH IN STACK 1\n 2.PUSH IN STACK 2 \n 3.POP FROM STACK 1 \n 4.POP FROM STACK 2\n 5.DISPLAY STACK 1\n 6.DISPLAY STACK 2\n 7.DESTORY STACK 1\n 8.DESTORY STACK 2\n 9.EXIT\n");
printf("Enter a Choice:");
scanf("%d", &ch);
switch(ch)
{
case 1: push1();
break;
case 2: push2();
break;
case 3: pop1();
break;
case 4: pop2();
break;
case 5: display1();
break;
case 6: display2();
break;
case 7: destory1();
break;
case 8: destory2();
break;
case 9: break;
default : printf("Entered a wrong choice\n");
}
}
while(ch!=9);
}
