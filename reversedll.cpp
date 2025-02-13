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
//REVERSE A DLL IN O(N) TIME
node* reversedll(node*head){
    node* curr=head;
    node* last=NULL;
    while(curr!=NULL){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
  return(last->back);
}
int main(){
    vector<int>arr={1,2,4,3};
    node*head=convertarr2DLL(arr);
    head=reversedll(head);
    print(head);
}
