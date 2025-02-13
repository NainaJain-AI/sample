#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data1,node*next1){
        data=data1;
        next=next1;
    }
    node(int data1){
        data=data1;
        next=nullptr;
    }
};
//CONVERT ARRAY TO LL
node* convertarr2LL(vector<int>&arr){
    if (arr.empty()) return nullptr; 
    node* head=new node(arr[0]);
    node*mover=head;
    for(int i=1;i<arr.size();i++){
       node* temp=new node(arr[i]);
       mover->next=temp; 
       mover=temp;
    }
    return head;
}
//DISPLAY THE LL
void display(node*head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL)
        cout<<"->";
        temp=temp->next;
    }
    cout<<"->NULL"<<endl;
}
//INSERT BEFORE HEAD OF LL
node* insertbeforehead(node*head,int val){
    node*temp=new node(val);
    if(head==NULL)return temp;
    temp->next=head;
    return temp;
}
//INSERT AFTER HEAD OF LL
node* insertafterhead(node*head,int val){
    node*temp=new node(val);
    if(head==NULL) {
        head=temp;
        return head;
    }
    temp->next=head->next;
    head->next=temp;
    return head;
}
//INSERT BEFORE TAIL OF LL
node* insertbeforetail(node*head,int val){
    node*temp=new node(val);
    if(head==NULL)return temp;
    if(head->next==NULL){
        temp->next=head;
        return temp;
    }
    node*tail=head;
    while(tail->next->next!=NULL)
    tail=tail->next;
    temp->next=tail->next;
    tail->next=temp;
    return head;
}
//INSERT AFTER TAIL OF LL
node* insertaftertail(node*head,int val){
    node*temp=new node(val);
    if(head==NULL) return temp;
    node*tail=head;
    while(tail->next!=NULL)
    tail=tail->next;
    tail->next=temp;
    return head;
}
//INSERTION BEFORE Kth ELEMENT
node* insertbeforeKth(node* head,int val,int k){
    if(k==1) return insertbeforehead(head, val);
    node* temp=new node(val);
    if(head==NULL) return temp;
    node* kth=head;
    int cnt=0;
    while(kth!=NULL&&cnt<=k){
        cnt++;
        if(cnt==k-1){
            temp->next=kth->next;
            kth->next=temp;
        }
        kth=kth->next;
    }
    return head;
}
//INSERTION AFTER Kth ELEMENT
node* insertafterKth(node* head,int val,int k){
    if(k==1) return insertafterhead(head,val);
    node* temp=new node(val);
    if(head==NULL) return temp;
    node* kth=head;
    int cnt=0;
    while(kth!=NULL&& cnt<=k){
        cnt++;
        if(cnt==k){
            temp->next=kth->next;
            kth->next=temp;
        }
        kth=kth->next;
    }
    return head;
}


int main(){
    vector<int> arr={1};
    node* head=convertarr2LL(arr);
    
    head=insertbeforeKth( head,100,1);
    display(head);
    head=insertafterKth( head,200,1);
    display(head);
    cout<<5/2+1;
}