#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// Q4.Longest substring non repeating characters

// Brute Force approach
// O(n^3)
bool condition(const string &s,int i,int j){
    unordered_set<char> st;
    for(int x=i; x<=j; x++){
        st.insert(s[x]);
        if(x-i+1 == st.size()){
            continue;
        }
        else{
            st.clear();
            return false;
        }
    }
    st.clear();
    return true;
}

bool condition1(const string &s,int i,int j){
    unordered_set<char> st;
    for(int x=i; x<=j; x++){
        st.insert(s[x]);
        if(x-i+1 != st.size()){
            st.clear();
            return false;
        }
    }
    st.clear();
    return true;
}

int version(string s){
    int n=s.size();
    
    if(n==0){
        return 0;
    }
    // n>=1
    int maxsize=1;
    for(int i=0; i<=n-1; i++){
        for(int j=i; j<=n-1; j++){
            // i is the starting point
            // j is the ending point
            if(condition1(s,i,j)){
                // Now the substring from i to j is completely unique
                maxsize=max(maxsize,j-i+1);
            }
            else{
                // Now the substring from i to j is not completely unique
                break;
                // There is no point in going further
            }
        }
    }
    return maxsize;
}

// Most optimal Approach
// O(n^2)
bool isunique(string &s, int i, int j,int next){
    for(int x=i; x<=j; x++){
        if(s[x]==s[next]){
            return false;
        }
    }
    return true;
}

int version1(string s){
    int n=s.size();

    if(n==0){
        return 0;
    }
    // n>=1
    // first window withsize one;
    int i=0;
    int j=0;
    int next=1;

    int maxsize=1;

    while(next<n){
        if(isunique(s,i,j,next)){
            j++;
            next++;
            maxsize=max(maxsize,j-i+1);
        }
        else{
            i++;
            if(i>j){
                j=i;
                next++;
            }
        }
    }
    return maxsize;
}

// using hash
// O(n)
int version2(string &s){
    int n=s.size();

    if(n==0){
        return 0;
    }

    // defining hash
    int hash[256]={0};

    // n>=1
    // first window withsize one;
    int i=0;
    int j=0;
    hash[s[0]]++;
    int next=1;

    int maxsize=1;

    while(next<n){
        if(hash[s[next]]==0){
            j++;
            next++;
            hash[s[j]]++;
            maxsize=max(maxsize,j-i+1);
        }
        else{
            hash[s[i]]--;
            i++;
            if(i>j){
                j=i;
                hash[s[j]]++;
                next++;
            }
        }
    }
    return maxsize;
}

int main(){
    string s="abcdefghabcabaacbd";
    cout << version(s) << endl;
    cout << version1(s) << endl;
    cout << version2(s) << endl;
}