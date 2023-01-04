#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev, *next;
};
struct node *first, *last, *newrec, *temp,*a,*b;
void ins_beg()
{
int x;
newrec = (struct node *) malloc (sizeof(struct node));
printf("Enter element to be inserted at begining : ");
scanf("%d",&x);
newrec -> data = x;
if(first == NULL)
{
first = last = newrec;
newrec -> prev = newrec -> next = NULL;
}
else
{
newrec -> next = first;
first -> prev =newrec; 
first = newrec;
newrec -> prev = NULL;
}
}
void ins_end()
{
int x;
newrec = (struct node *) malloc (sizeof (struct node));
printf("Enter element to be inserted at end : ");
scanf("%d",&x);
newrec -> data = x;
if (first == NULL)
{
first = last = newrec;
newrec -> prev = newrec -> next = NULL;
}
else
{
newrec -> prev = last;
last -> next = newrec; 
last = newrec;
newrec -> next = NULL;
}
}
void ins_pos(int p)
{
int x,i;
newrec =(struct node*) malloc (sizeof (struct node));
printf("Enter element to be inserted : ");
scanf("%d", &x);
newrec -> data = x;
temp = first;
for(int i = 1; i<p-1;i++) 
temp = temp -> next;
struct node *a = temp -> next; 
a -> prev = newrec;
newrec -> next = a; 
temp -> next = newrec; 
newrec -> prev = temp;
}
void ins_ele(int y)
{
int x;
newrec = (struct node *) malloc (sizeof (struct node));
printf("Enter element to be inserted after element : ");
scanf("%d", &x);
newrec->data=x; 
temp = first;
while(temp -> data != y)
temp = temp -> next;
struct node *a = temp -> next; 
a -> prev = newrec;
newrec -> next = a; 
temp -> next = newrec; 
newrec -> prev = temp;
}
void del_beg()
{
if (first==NULL)
printf("Link list Underflow\n ");
else
{
printf("Element deleted is %d\n",first -> data); 
if(first==last)
first=last=NULL;
else
first=first->next; 
first -> prev = NULL;
}
}
void del_end ()
{
if(first==NULL)
printf("Link list Underflow\n");
else
{
printf("Element deleted is %d\n",last->data); 
if(first==last)
first=last=NULL;
else
{
last = last -> prev;
}
last -> next = NULL;
}
}
void del_pos(int p)
{
int i;
temp=first;
for(i=1;i<p-1;i++)
temp = temp->next;
struct node * a = temp ->next, *b = a->next;
printf("Element deleted is %d at postion %d\n", a->data, p); 
temp->next= b;
b->prev = temp;
}
void del_ele(int y)
{
temp=first;
while(temp->data != y)
temp=temp->next;
struct node * a = temp ->next, *b = a->next;
printf("Element deleted is %d after element %d\n", a-> data, y); 
temp->next= b;
b->prev = temp;
}
void display_f()
{
if (first==NULL)
printf ("Link list under flow\n");
else
{
printf("The elements of Doubly Link List in Forward order are\n");
temp=first;
while(temp!=NULL)
{
printf("%d\n",temp->data); 
temp=temp->next;
}
}
}
void display_b()
{
if (first==NULL)
printf ("Link list under flow\n");
else
{
printf("The elements of Doubly Link List in Backward order are\n");
temp=last;
while(temp!=NULL)
{
printf("%d\n",temp->data); 
temp=temp->prev;
}
}
}
void destroy()
{
printf("The Doubly link list is destroyed\n");
first=last=NULL;
}
void main()
{
int ch;
first=last=NULL;
do
{
printf("\nMENU\n1.Insert at begining\n2.Insert at end\n3.Insert at position\n4.Insert after element\n5.Delete at begining\n6.Delete at end\n7.Delete at position\n8.Delete after element\n9.Display in Forward order\n10.Display in backward order\n11.Destroy\n12.Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
switch (ch)
{
case 1:ins_beg();
break;
case 2:ins_end();
break;
case 3:
{
int p;
printf("Enter the position : ");
scanf("%d",&p );
ins_pos(p);
}
break;
case 4:
{
int y;
printf("Enter the element : ");
scanf("%d", &y);
ins_ele(y);
}
break;
case 5:del_beg();
break;
case 6:del_end();
break;
case 7:
{
int p;
printf("Enter the position : ");
scanf("%d", &p);
del_pos(p);
}
break;
case 8:
{
int y;
printf("Enter the element : ");
scanf("%d", &y);
del_ele(y);
}
break;
case 9:display_f();
break;
case 10:display_b();
break;
case 11:destroy();
break;
case 12:break;
}
}
while (ch != 12);
}
