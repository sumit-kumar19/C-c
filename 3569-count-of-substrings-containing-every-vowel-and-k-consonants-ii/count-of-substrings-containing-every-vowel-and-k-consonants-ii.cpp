class Solution {
    typedef long long ll;
public:
    bool isVowel(char a){
        return a=='a'||a=='i'||a=='o'||a=='e'||a=='u';
    }
    long long f(string word, int k){
        if(k<0) return 0;
        unordered_map<char,ll> freq;
        int  vCount=0,totalVCount = 0;
        int i=0,j=0, n = word.size();
        ll res = 0;
        while(j<n){
            if(isVowel(word[j])){
                totalVCount++;
                if(freq.find(word[j])!=freq.end()){
                    if(freq[word[j]]<i){
                    vCount++;
                    }
                    freq[word[j]]=j;
                }
                else if(freq.find(word[j])==freq.end()){
                    freq[word[j]]=j;
                    vCount++;
                }
            }
            while((j-i+1 - totalVCount)>k){
                if(isVowel(word[i])){
                    if(freq[word[i]]==i) vCount--;
                    totalVCount--;
                }
                i++;
            }
            if(vCount==5){
                int x = min({freq['a'],freq['e'],freq['i'],freq['o'],freq['u']});
                res+=(x-i+1);
            }
            j++;
        }
        return res;
    }
    long long countOfSubstrings(string word, int k) {
        return f(word,k)-f(word,k-1);
    }
};