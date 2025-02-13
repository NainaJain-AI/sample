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

//DELETION OF HEAD
node* deletehead(node* head){
    if(head==NULL) return head;
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
//DELETION OF TAIL
node* deletetail(node*head){
    if(head==NULL||head->next==NULL) return NULL;
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
//DELETE Kth ELEMENT
node* deleteKth(node*head,int k){
    if(head==NULL)return head;
    if(k==1) return deletehead(head);
    int cnt=0;
    node* temp=head;
    node* prev=NULL;
    while(temp!=NULL&&cnt<=k){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
//DELETE BY VALUE
node* deletebyval(node*head,int k){
    if(head==NULL)return head;
    if(head->data==k) return deletehead(head);
    node* temp=head;
    node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==k){
            prev->next=temp->next;
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    node* head=convertarr2LL(arr);
    head=deleteKth(head,8);
    display(head);
    head=deletebyval(head,5);
    display(head);
    
}
