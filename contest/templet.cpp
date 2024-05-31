    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    bool isStrong(string& str);
    void solve(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            vector<ll> arr1(n);
            vector<ll> arr2(n+1);
            for(int i=0;i<n;i++)
            cin>>arr1[i];
            for(int i=0;i<n+1;i++)
            cin>>arr2[i];
            ll mindiff=INT_MAX;
            ll elm;
            int lm=-1;
            ll count=0;
            int target=arr2[n];

            // for(int i=0;i<n;i++){
            //     if(mindiff> target-arr1[i]){
            //         mindiff=target-arr1[i];
            //         elm=arr1[i];
            //     }
            // }
            // arr1.push_back(elm);
            for(int i=0;i<n;i++){
                count+=abs(arr1[i]-arr2[i]);
                if(mindiff> target-arr1[i]){
                    mindiff=target-arr1[i];
                    elm=arr1[i];
                }
                if(target<=arr1[i]&& target>=arr2[i]||target>=arr1[i]&& target<=arr2[i])
                lm=0;
            }
            if(lm==0)
            cout<<count+1<<endl;
            else
            cout<<count+abs(elm-target)<<endl;

        }
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        solve();
    }