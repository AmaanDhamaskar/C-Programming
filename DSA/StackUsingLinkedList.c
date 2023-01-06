#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top;
struct node *newrec;

void push(){
    int x;
    printf("Enter Element To Be Pushed\n");
    scanf("%d",&x);
    newrec=(struct node *)malloc(sizeof(node));
    newrec->data=x;
    newrec->next=top;
    top=newrec;
}

void pop(){
    if (top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        printf("Element Popped Is %d",top->data);
        top=top->next;
    }
}

void display(){
    if (top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        printf("Elements In Stack Are \n");
        struct node *temp;
        temp=top;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void destroy(){
    top=NULL;
    printf("Stack Destroyed");
}

int main(){
    int ch=0;
    top=NULL;
    do{
        printf("\n\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.DESTROY\n5.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : display();
            break;
            case 4 : destroy();
            break;
        }
    }while(ch!=5);
}
