#include <stdio.h>

struct queue{
    int a[5];
    int front,rear;
};

struct queue q;

void insert(){
    int x;
    if (q.rear==4){
        printf("A.P.Q Overflow\n");
    }
    else{
        printf("Enter Element To Be Inserted\n");
        scanf("%d",&x);
        q.rear++;
        q.a[q.rear]=x;
        if (q.front==-1)
            q.front++;
    }
    printf("Element %d Has Been Inserted\n",x);
}

void qdelete(){
    if (q.front==-1){
        printf("A.P.Q Underflow\n");
    }
    else{
        int min,p,i;
        p=q.front;
        min=q.a[q.front];
        for (i=q.front;i<q.rear;i++){
            if (q.a[i]<min){
                min=q.a[i];
                p=i;
            }
        }
        printf("Element Deleted Is %d \n",q.a[p]);
        for(i=p;i<q.rear;i++)
            q.a[i]=q.a[i+1];
        q.rear--;
    }
}

void display(){
    if (q.rear==-1)
        printf("A.P.Q Underflow\n");
    else{
        printf("Elements Of Queue Are\n");
        for (int i=0;i<=q.rear;i++)
            printf("%d\n",q.a[i]);
    }
}

void destroy(){
    q.front=q.rear=-1;
    printf("The Queue Has Been Destroyed\n");
}

void main() {
    int ch;
    q.front=q.rear=-1;
    while(1){
        printf("\nMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.DESTROY\n5.EXIT\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : insert();
            break;
            case 2 : qdelete();
            break;
            case 3 : display();
            break;
            case 4 : destroy();
            break;
        }
        if(ch==5)
            break;
    }
    return;
}
