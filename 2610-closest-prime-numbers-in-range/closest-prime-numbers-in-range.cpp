class Solution {
public:
vector<int> isprime(int l,int r)
{
    vector<bool> istrue(r+1,true);
    istrue[0]=istrue[1]=false;
    for (int i = 2; i * i <= r; ++i) {
        if (istrue[i]) {
            for (int j = i * i; j <= r; j += i) {
                istrue[j] = false;
            }
        }
    }
    vector<int> res;
    for(int i=l;i<r+1;i++){
        if(istrue[i]==true)
        res.push_back(i);
    }
    return res;

}
    vector<int> closestPrimes(int left, int right) {
       vector<int> prime = isprime(left,right);
        if(prime.size()<2) return {-1,-1};

        pair<int,int> mini ={prime[0],prime[1]};
        for(int i =0;i<prime.size()-1;i++){
           if(prime[i+1]-prime[i]<mini.second-mini.first){
            mini = {prime[i],prime[i+1]};
           }
        }
        return {mini.first,mini.second};
        
    }
};