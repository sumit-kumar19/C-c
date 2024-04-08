#include<bits/stdc++.h>
using namespace std ;

int sqrrt(int x){
   if(x<2)return x;
    int l=2,h=x/2;
    long int mid, ans;
    while(l<=h){
      mid=l+(h-l)/2;
      ans=mid*mid;
      if(ans==x)
      return mid;
      else if(ans>x)
      h=mid-1;
      else if(ans<x)
      l=mid+1;  
    }
    return h;
}

int main(){
    int x=15;
    int temp =sqrrt(x);
     cout <<temp;

}
