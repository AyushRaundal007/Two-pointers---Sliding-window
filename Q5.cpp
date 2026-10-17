#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// most optimal approach
int longestSubstring2(string s, int k) {
        int n=s.size();
        int maxlen=0;

        for(int maxUnique=1; maxUnique<=26; maxUnique++){
            // Now the maximum number of unique caharacters that the sliding window can have is maxUnique
            vector<int> freq(26,0);

            int unique=0;   // it tracks the all number of unique characters in the sliding window 
            int count=0;   // it tracks the number of unique characters that are repeated atleast k times

            // defining the window starting from i=0 -> j-1 , j=0 is the next character
            int i=0; 
            int j=0;

            while(j<n){
                char ch=s[j];

                if(freq[ch -'a']==0){
                    // ch is new unique character that we have found 
                    unique++;
                }
                if(freq[ch - 'a']==k-1){
                    // when ch is repeated exactly k-1 times
                    // and we found ch one more time
                    // number of unique characters where each character is repeated atleast k times
                    count++;
                }
                freq[ch - 'a']++;

                // Now shrink the window till the number of unique characters in the window becomes maxUnique
                while(unique>maxUnique){
                    char start_ch=s[i];

                    if(freq[start_ch - 'a']==1){
                        unique--;
                    }
                    if(freq[start_ch - 'a']==k){
                        count--;
                    }
                    freq[start_ch - 'a']--;

                    i++;
                }
                
                if(unique==maxUnique && unique==count){
                    maxlen=max(maxlen,j-i+1);
                }

                j++;
            }
        }
        return maxlen;
    }

// Brute force approach
bool condition(const string &s,int i,int j,int k){
        unordered_map <char,int> hash;
        for(int x=i; x<=j; x++){
            hash[s[x]]++;
        }

        for(auto &x : hash){
            if(x.second<k){
                return false;
            }
        }
        return true;
    }

int longestSubstring1(string s, int k) {
    int n=s.size();
    int maxlen=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // i is start
            // j is end
            if(condition(s,i,j,k)){
                // if condition is true
                // when each character in the substring is repeated >= k times
                maxlen=max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}  

int main(){
    string S1="aaabbbaaaccccccbbbbbaaajkhhfhsfhihishisufhibihiihhggggghghhoioiauodaouduhdaiuhdajhsdadfhsuehiuefsgbcsdvbsjh";
    cout << longestSubstring1(S1,3) << endl;
    cout << longestSubstring2(S1,3) << endl;
}    