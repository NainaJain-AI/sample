#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* createnode(int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
 int display(node*head)
 {
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
 }
 node* deletetail(node*head){
    if(head==NULL|| head->next==NULL) return head;
    node* temp=head;
    while(temp->next->next!=NULL)
     temp=temp->next;
    free(temp->next);
    temp->next=NULL;
    return head;
 }
 int main()
 {
    node* head=NULL;
    node* n1=NULL;
    node* n2=NULL;
    head=createnode(10);
    n1=createnode(20);
    n2=createnode(50);
    head->next=n1;
    n1->next=n2;
    deletetail(head);
    display(head);

 }