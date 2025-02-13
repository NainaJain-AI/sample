#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* back;
    public:
    node(int data1,node* next1,node*back1){
        data=data1;
        next=next1;
        back=back1;
    }
    node(int data1){
        data=data1;
        next= NULL;
        back= NULL;
    }
};
//CONVERT ARRAY TO DLL
node* convertarr2DLL(vector<int>&arr){
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i],NULL,prev);
        prev->next=temp;
        prev=temp;
    }
return head;
} 
//DISPLAY DLL
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"<->";
        head=head->next;
    }
}
//DELETION OF HEAD
node* deletehead(node*head){
    if(head==NULL||head->next==NULL)
    return NULL;
    node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}
//DELETION OF TAIL
node* deletetail(node*head){
    if(head==NULL||head->next==NULL)
    return NULL;
    node* tail=head;
    while(tail->next!=NULL)
    tail=tail->next;
    node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    delete tail;
    return head;
}
//DELETION OF Kth ELEMENT
node* deletekthelement(node*head,int k){
    node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    node*prev=temp->back;
    node*front=temp->next;
    if(front==NULL&&prev==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){                     //HEAD
      deletehead(head);
      return head;
    }
    else if(front==NULL){                     //TAIL
      deletetail(head);
      return head;
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        delete temp;
        return head;
    }
}
//DELETION OF THE GIVEN NODE
node*deleteatnode(node*head,node*temp){
    node* prev=temp->back;
    node* front=temp->next;
    if(front==NULL&&prev==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){                     //HEAD
      deletehead(head);
      return head;
    }
    else if(front==NULL){                     //TAIL
      deletetail(head);
      return head;
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        delete temp;
        return head;
    }
}

int main(){
    vector<int>arr={1,2,4,3};

    return 0;
}
