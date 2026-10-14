#include<iostream>
#include<vector>
using namespace std;

// Q1. Find the maximum sum of k consecutive elements of an array of integers

int version0(vector<int> &nums,int k){
    int n=nums.size();
    // k is less than n
    int max_sum=0;
    for(int i=0,j=k-1; i<=(n-k),j<=(n-1); i++,j++){
        int sum=0;
        for(int x=i; x<=j; x++){
            sum=sum+nums[x];
        }
        max_sum=max(max_sum,sum);
    }
    return max_sum;
}

// optimal approaches
int version1(vector<int> &nums,int k){
    int n=nums.size();
    int sum=0; // first window sum
    for(int i=0; i<k; i++){
        sum=sum+nums[i];
    }

    int maxsum=sum;
    for(int start=1,end=k; end<n; start++,end++){
        sum=sum-nums[start-1]+nums[end];
        maxsum=max(sum,maxsum);
    }

    return maxsum;
}

int version2(vector<int> &nums,int k){
    int n=nums.size();
    int sum=0; // sum variable tracks the sum of each window
    int maxsum=0; // maxsum variable tracks the maximum sum among all the windows

    for(int start=0,end=k-1; end<n; start++,end++){
        if(start==0){
            for(int i=0; i<k; i++){
                sum=sum+nums[i];
            }
            maxsum=sum;
        }
        else{
            sum=sum-nums[start-1]+nums[end];
            maxsum=max(sum,maxsum);
        }
    }

    return maxsum;
}

int main(){
    vector<int> nums={12,2,3,6,8,0,1,2,4,6,78,94,23,1};
    cout << version0(nums,3) << endl;
    cout << version1(nums,3) << endl;
    cout << version2(nums,3) << endl;

}