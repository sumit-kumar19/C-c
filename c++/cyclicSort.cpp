#include<bits/stdc++.h>
using namespace std ;

int main(){
    vector<int> arr={4,3,2,1,5};
    for(int i=0;i<arr.size();){
  if(i!=arr[i]-1)
  swap(arr[i],arr[arr[i]-1]);
  else
  i++;
    }
    for(int i=0;i<arr.size();i++){
      cout<<arr[i]<<" ";
    }
}