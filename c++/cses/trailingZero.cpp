#include<bits/stdc++.h>
using namespace std;
 int main(){
    int n;
    cin>>n;
    int s=0,k=0;
    while(n>=5){
     s=n/5;
     k=k+s;
     n=n/5;
}
    cout<<k;
 }