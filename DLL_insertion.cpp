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
        cout<<head->data;
        if(head->next!=NULL)cout<<"<->";
        head=head->next;
    }
     cout << "-> NULL" << endl;
}
//INSERTION BEFORE HEAD
node* insertbeforehead(node* head,int val) {
    node*newhead=new node(val,head,nullptr);
    head->back=newhead;
    return newhead;
}
//INSERTION BEFORE TAIL
node* insertbeforetail(node* head,int val){
    if(head==NULL)
    return insertbeforehead(head,val);
    node*tail=head;
    while(tail->next!=NULL)
    tail=tail->next;
    node*prev=tail->back;
    node*newnode=new node(val,tail,prev);
    tail->back=newnode;
    prev->next=newnode;
    return head;
}
//INSERTION BEFORE Kth ELEMENT
node* insertbeforekthelement(node*head,int k,int val){
    if(k==1)
    return insertbeforehead(head,val);
    node* temp=head;
    int cnt=0;
    while(temp!=NULL&&cnt<k){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    node*prev=temp->back;
    node*newnode=new node(val,temp,prev);
    if(prev!=nullptr)
        temp->back=newnode;
        prev->next=newnode;
    return head;
}
//INSERTION BEFORE GIVEN NODE
void insertbeforenode(node*temp,int val){
    node*prev=temp->back;
    node*newnode=new node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
}
int main(){
    vector<int>arr={1,2,4,3};
    node*head=convertarr2DLL(arr);
    head=insertbeforehead(head,10);
     print(head);
     cout<<"\n";
    head=insertbeforetail(head,20);
     print(head);
     cout<<"\n";
    head=insertbeforekthelement(head,3,50);
     print(head);
     cout<<"\n";
    insertbeforenode(head->next,100);
    print(head);
    return 0;
}