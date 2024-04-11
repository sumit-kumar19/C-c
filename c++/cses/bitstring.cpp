#include<bits/stdc++.h>
using namespace std;
#define mm 1000000007

int main(){
    int n;
    cin>>n;
    if(n==0)cout<<1;
    else{
    int poe=1;
    for(int i=0;i<n;i++){
        poe=poe*2;
        poe%=mm;
    }
    cout<<poe;
    }
}