#include<iostream>
#include<vector>
using namespace std;

// Q3. Maximum points you can obtain from cards

int version(const vector<int> &nums,int k){
    int n=nums.size();
    // Total iterations k+1
    // first k elements last 0 elements
    // first k-1 elements last 1 elements
    // first k-2 elements last 2 elements
    
    // first 0 elements last k elements

    int sum=0; // sum of first k elements
    for(int i=0; i<k; i++){
        sum+=nums[i];
    }

    int maxsum=sum;
    // Now k number of iterations
    // in each iteration we will remove element at the index i and we will add the element at the index j
    // delete element at i , add element at j
    for(int i=k-1,j=n-1; i>=0; i--,j--){
        // updating the sum
        sum=sum-nums[i]+nums[j];
        // sum updated
        maxsum=max(sum,maxsum);
    }

    return maxsum;
}

int version1(const vector<int> &nums,int k){
    int n=nums.size();

    // n iterations
    int arraysum=0;
    for(int i=0; i<n; i++){
        arraysum+=nums[i];
    }

    // creating the first constant window of size n-k
    // n-k iterations
    int windowsum=0;
    for(int i=0; i<n-k; i++){
        windowsum+=nums[i];
    }

    int minsum=windowsum;    // minimum sum of the constant window

    for(int start=1,end=n-k; end<n; start++,end++){
        // updating windowsum
        windowsum=windowsum-nums[start-1]+nums[end];
        // windowsum updated for this iteration
        minsum=min(windowsum,minsum); 
    }

    return arraysum-minsum;
}

int version2(const vector<int> &nums,int k){
    int n=nums.size();

    // n iterations
    int arraysum=0;
    int windowsum=0;   // creating the first constant window of size n-k
    for(int i=0; i<n; i++){
        if(i<n-k){
            windowsum+=nums[i];
        }
        arraysum+=nums[i];
    }

    int minsum=windowsum;    // minimum sum of the constant window

    for(int start=1,end=n-k; end<n; start++,end++){
        // updating windowsum
        windowsum=windowsum-nums[start-1]+nums[end];
        // windowsum updated for this iteration
        minsum=min(windowsum,minsum); 
    }

    return arraysum-minsum;
}
int main(){
    vector<int> nums={6,2,3,4,7,2,1,7,1};
    int k=4;
    cout << version(nums,k);
    cout << version1(nums,k);  
    cout << version2(nums,k);
}