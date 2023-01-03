#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *first,*last,*temp,*temp1,*newrec;

void ins_beg(){
    int x;
    newrec=(struct node *)malloc(sizeof(struct node));
    printf("Enter Element To Be Inserted\n");
    scanf("%d",&x);
    newrec->data=x;
    if(first==NULL){
        first=last=newrec;
        newrec->next=NULL;
    }
    else{
        newrec->next=first;
        first=newrec;
    }
}

void ins_end(){
    int x;
    newrec=(struct node *)malloc(sizeof(struct node));
    printf("Enter Element To Be Inserted\n");
    scanf("%d",&x);
    newrec->data=x;
    if(first==NULL){
        first=last=newrec;
        newrec->next=NULL;
    }
    else{
        last->next=newrec;
        last=newrec;
        newrec->next=NULL;
    }
}

void ins_pos(int p){
    int x,i;
    newrec=(struct node *)malloc(sizeof(struct node));
    printf("Enter Element To Be Inserted\n");
    scanf("%d",&x);
    newrec->data=x;
    temp=first;
    for(i=1;i<p-1;i++)
        temp=temp->next;
    newrec->next=temp->next;
    temp->next=newrec;
}

void ins_ele(int v){
    int x;
    newrec=(struct node *)malloc(sizeof(struct node));
    printf("Enter Element To Be Inserted\n");
    scanf("%d",&x);
    newrec->data=x;
    temp=first;
    while(temp->data!=v){
        temp=temp->next;
    }
    newrec->next=temp->next;
    temp->next=newrec;
}

void del_beg(){
    if(first==NULL){
        printf("Linked List Underflow\n");
    }
    else{
        printf("Element Deleted Is %d \n",first->data);
        if(first==last){
            first=last=NULL;
        }
        else{
            first=first->next;
        }
    }
}

void del_end(){
    if(first==NULL){
        printf("Linked List Underflow\n");
    }
    else{
        printf("Element Deleted Is %d \n",last->data);
        if(first==last){
            first=last=NULL;
        }
        else{
            temp=first;
            while(temp->next!=last)
                temp=temp->next;
            temp->next=NULL;
            last=temp;
        }
    }
}

void del_pos(int p){
    if(first==NULL){
        printf("Linked List Underflow\n");
    }
    else{
        int i;
        temp=first;
        for(i=1;i<p-1;i++){
            temp=temp->next;
        }
        temp1=temp->next;
        printf("Element Deleted Is %d \n",temp1->data);
        temp->next=temp1->next;
    }
}

void del_ele(int v){
    if(first==NULL){
        printf("Linked List Underflow\n");
    }
    else{
        temp=temp1=first;
        while(temp1->data!=v)
            temp1=temp1->next;
        while(temp->next!=temp1)
            temp=temp->next;
        printf("Element Deleted Is %d \n",temp1->data);
        temp->next=temp1->next;
    }
}

void display(){
    if(first==NULL){
        printf("Linked List Underflow\n");
    }
    else{
        temp=first;
        printf("The Linked List Is \n");
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void destroy(){
    printf("Linked List Destroyed\n");
    first=last=NULL;
}

int main() {
    first=last=NULL;
    int ch=1;
    int x;
    while(ch!=11){
        printf("\nMENU\n\n1.INSERT AT BEGINNING\t2.INSERT AT END\n3.INSERT AT POSITION\t4.INSERT AFTER ELEMENT\n5.DELETE AT BEGINNING\t6.DELETE AT END\n7.DELETE AT POSITION\t8.DELETE AFTER ELEMENT\n9.DISPLAY\t\t\t\t10.DESTROY\n11.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : ins_beg();
            break;
            case 2 : ins_end();
            break;
            case 3 : printf("Enter Position At Which Element Is To Be Inserted\n");
            scanf("%d",&x);
            ins_pos(x);
            break;
            case 4 : printf("Enter Element After Which New Element Is To Be Inserted\n");
            scanf("%d",&x);
            ins_ele(x);
            break;
            case 5 : del_beg();
            break;
            case 6 : del_end();
            break;
            case 7 : printf("Enter Position At Which Element Is To Be Deleted\n");
            scanf("%d",&x);
            del_pos(x);
            break;
            case 8 : printf("Enter Element After Which Element Is To Be Deleted\n");
            scanf("%d",&x);
            del_ele(x);
            break;
            case 9 : display();
            break;
            case 10 : destroy();
            break;

        }
    }

    return 0;
}
