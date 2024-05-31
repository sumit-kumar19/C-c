#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> word = {"the", "quick", "fox", "jumps", "over", "lazy", "brown", "dog"};
    string word1, word2;
    word1="fox";
    word2="dog";
    int pos1 = -1, pos2 = -1;
    int dist = word.size(); 

    for(int i = 0; i < word.size(); ++i) {

        if(word[i] == word1) 
            pos1 = i;
        if(word[i] == word2) 
            pos2 = i;
        if(pos1 != -1 && pos2 != -1) 
            dist = min(dist, abs(pos1 - pos2));
        
    }

    if(dist != word.size())
        cout << dist;
   else 
     cout << "Words not found.";
    
    return 0;
}
