//mid niklo aur uske bad left or right move karo
#include <bits/stdc++.h>
using namespace std;
 int Occurence(int arr[],int key,int n){
    int l=0,h=n-1;
     int mid;
     int flag=-1;
     while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==key){
           flag=1;
        break;
        }
        if(arr[mid]<key)
        l=mid+1;
        else
        h=mid-1;
     }
     if(flag==-1)
     return -1;
     int count=1;
     l=mid-1;
     while(l>=0&&arr[l]==key){
        count++;
        l--;
     }
     l=mid+1;
     while(l<n&&arr[l]==key){
        count++;
        l++;
     }
     return count;

 }
 int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter element";
    cin>>key;
    int val=Occurence(arr,key,n);
    cout<<val;
 }