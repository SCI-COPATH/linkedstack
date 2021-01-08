#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* createNode(){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Memary making failed");
        return NULL;
    }
    return ptr;
}
int isNull(struct node *head){
    if(head==NULL)
        return 1;
    return 0;
}
struct node* push(struct node *head,int value){
    struct node *ptr;
    if(isNull(head)==1){
        head=createNode();
        head->data=value;
        head->link=NULL;
    }
    else{
        ptr=createNode();
        ptr->link=head;
        ptr->data=value;
        head=ptr;
        ptr=NULL;
    }
    return head;
}
struct node* pop(struct node *head){
    struct node* ptr=head;
    if(isNull(head)==1){
        printf("Stack is underflow\n");
        return head;
    }
    else{
        printf("Removing %d in stack\n",head->data);
        head=head->link;
        free(ptr);
        ptr=NULL;
    }
    return head;
}
void view(struct node *head){
    struct node *ptr=head;
    if(isNull(head)==1)
        printf("Stack is Empty\n");
    else {
        printf("\nStack\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}
void main(){
    struct node *head=NULL;
    int dis,value;
    do{
        printf("1-PUSH\n2-POP\n3-VIEW\nENTER : ");
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter value : ");
                    scanf("%d",&value);
                    head=push(head,value);
                    break;
            case 2:head=pop(head);
                    break;
            case 3:view(head);
            case 4:break;
            default:printf("Wrong input\n");
        }
    }while(dis!=4);
}