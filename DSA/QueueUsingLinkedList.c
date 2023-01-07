#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};


struct node *front,*rear,*temp,*newrec;

void insert(){
    int x;
    printf("Enter Element To Be Inserted\n");
    scanf("%d",&x);
    printf("\n");
    newrec=(struct node *)malloc(sizeof(struct node));
    newrec->data=x;
    if (front==NULL){
        front=rear=newrec;
    }
    else{
        rear->next=newrec;
        rear=newrec;
    }
    newrec->next=NULL;
}

void Delete(){
    if (front==NULL){
        printf("Queue Underflow\n");
    }
    else{
        printf("Element Deleted Is %d\n",front->data);
        if(front==rear)
            front=rear=NULL;
        else
            front=front->next;
    }
}

void display(){
    if (front==NULL){
        printf("Queue Underflow\n");
    }
    else{
        printf("Elements In Queue Are \n");
        temp=front;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void destroy(){
    front=rear=NULL;
    printf("Queue Destroyed");
}

int main(){
    int ch=0;
    front=rear=NULL;
    do{
        printf("\nMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.DESTROY\n5.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : insert();
            break;
            case 2 : Delete();
            break;
            case 3 : display();
            break;
            case 4 : destroy();
            break;
        }
    }while(ch!=5);
}
