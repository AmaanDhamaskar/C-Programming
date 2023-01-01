#include<stdio.h>
struct stack
{
    int a[5];
    int top;
} s;
void push()
{
    int x;
    if (s.top == 4)
    printf("Stack is overflow\n");
    else
    {
    printf("Enter element to push in stack:");
    scanf("%d", &x);
    s.top++;
    s.a[s.top]=x;
    }
}
void pop()
{
    if (s.top == -1)
    printf("Stack is underflow\n");
    else
    {
    printf("Element poped in the stack is %d \n",s.a[s.top]);
    s.top--;
    }
}

void display()
{
    if (s.top == -1)
    printf("Stack is underflow\n");
    else
    {
    printf("Elements of the stack are \n");
    for(int i = 0; i<= s.top; i++)
    printf("%d\n",s.a[i]);
    }
}
void destory()
{
    s.top = -1;
    printf("Stack is destory \n");
}
void main()
{
    int ch;
    s.top = -1;
    do
    {
    printf("MENU\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.DESTORY\n 5.EXIT\n");
    printf("Enter a Choice:");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1: push();
    break;
    case 2: pop();
    break;
    case 3: display();
    break;
    case 4: destory();
    break;
    case 5: break;
    default : printf("Entered a wrong choice\n");
    }
    } while(ch!=5);
}
