#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={7,7,2,5,9,9};
    int k=0;
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr.size();j++)
        if(i==j)break;
        if(a[i]!=a[j]){
            a[k++]=a[i];
        }
    }
    cout<<k;
    cout<<arr;
}