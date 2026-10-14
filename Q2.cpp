#include<iostream>
#include<vector>
using namespace std;

// Q2. Longest subarray with the condition : sum of that subarray <=k

// brutest 
int version0(vector<int> &nums,int k){
    int n=nums.size();
    int max_size=1;
    for(int i=0; i<=n-2; i++){
        for(int j=i; j<=n-1; j++){
            // i is the starting point of the substring and 
            // j is the ending point of the substring
            int sum=0;
            for(int x=i; x<=j; x++){
                sum=sum+nums[x];
            }
            if(sum<=k){
               max_size=max(max_size,j-i+1);
            }
        }
    }
    return max_size;
}
// brute force
int version1(vector<int> &nums,int k){
    int n=nums.size();
    int max_size=1;
    for(int i=0; i<=n-2; i++){
        int sum=0;
        for(int j=i; j<=n-1; j++){
            // i is the starting point of the substring and 
            // j is the ending point of the substring
            sum=sum+nums[j];
            // here now sum represents the current sum of the substring starting with i and ending with j
            if(sum<=k){
                max_size=max(max_size,j-i+1);
            }
        }
    }
    return max_size;
}

// brute force optimized
// Applicable only when all the numbers are positive or non-negative
int version2(vector<int> &nums,int k){
    int n=nums.size();
    int max_size=1;
    for(int i=0; i<=n-2; i++){
        int sum=0;
        for(int j=i; j<=n-1; j++){
            // i is the starting point of the substring and 
            // j is the ending point of the substring
            sum=sum+nums[j];
            // here now sum represents the current sum of the substring starting with i and ending with j
            if(sum<=k){
                max_size=max(max_size,j-i+1);
            }
            else{ // optimization
                // if sum>k
                // we break the ending point loop because the further adding of positive numbers in the sum is just going to increase the sum
                break;
            }
        }
    }
    return max_size;
}

// Better approach - two pointer and sliding window 

    // so we will start with a window of size one
    // each window will have a starting point and an ending point
    // the window will have a starting point l as (left iterator)
    // the window will also have an ending point r as (right iterator)
    
    // So whenever the condition is true we expand
    // and whenever the condition is false we shrink

// it has bugs
int version3(vector<int> &nums,int k){
    int n=nums.size();
    int max_size=1;

    if(n==0){
        return 0;
    }

// first window and its sum defined
    int l=0;
    int r=0;
    int sum=nums[r];

    while(r<n){

        if(sum<=k){
            max_size=max(max_size,r-l+1);
            r++; // expanding the window
            if(r<n){
            sum=sum+nums[r]; // updating the sum of new updated window
            }
        }
        else{
            // sum>k
            l++; // shrinking the window
            sum=sum-nums[l-1]; // updating the sum of the new updated window
            if(l>r){    // the window became empty after updation
                r=l;    // restart the window at l
                if(r<n){ // when the window is valid
                    sum=nums[r];
                }
            }
        }
    }
    return max_size;
}

// When the Question is asking me about find the subarray then we use u and v variables to store l and r ,And we can shrink it however the way we want
// But suppose if the question is just asking me about the maximum size of the subarray do i need to shrink the subarray below the maxsize
// so we will not shrink the subarray below max size

// while loop's each iteration represents a window;

int version4(vector<int> & nums,int k){
    int n=nums.size();

    if(n==0){
        return 0;
    }

    // first window with size = 1 defined
    int l=0;
    int r=0;
    int sum=nums[r];

    int maxsize=0;

    while(r<n){

        if(sum<=k){
            maxsize=max(maxsize,r-l+1);
            r++;   // window expanded
            if(r<n){   // window sum updated
                sum=sum+nums[r];
            }
        }
        else{
            // sum>k
            l++; // window just moved forward
            r++;
            sum=sum-nums[l-1];
            if(r<n){
                sum=sum+nums[r];
            }
        }
        // Here the window is never going to shrink and we are constantly searching for a valid window satisfying the condition with size = maxsize+1 and when we found such valid window we update maxsize=max(maxsize,r-l+1)
    }
    return maxsize;
}

// Since the window size never decreases, r-l at the end would also equal the answer, so return r-l; would work too

int main(){
    vector<int> nums={1,2,3,4,56,7,8,99};
    cout << version4(nums,20) << endl;
}

/*
int version3(vector<int> &nums,int k){
    int n=nums.size();
    if(n==0) return 0;
    int max_size=0;               // 0, not 1: every element could be > k

    // first window and its sum defined
    int l=0;
    int r=0;
    int sum=nums[r];

    while(r<n){                   // l<=r check removed, handled in else

        if(sum<=k){
            max_size=max(max_size,r-l+1);
            r++; // expanding the window
            if(r<n) sum=sum+nums[r]; // only read when r is in bounds
        }
        else{
            // sum>k
            sum=sum-nums[l];
            l++; // shrinking the window

            if(l>r){             // window became empty
                r=l;             // restart the window at l
                sum=0;
                if(r<n) sum=nums[r];
            }
        }
    }
    return max_size;
}
*/