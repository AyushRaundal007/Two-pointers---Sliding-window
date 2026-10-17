#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Q6. Maximum number of consecutive ones I

// Brute force approach
int max_ones_Ia(const vector<int> &nums){
    int n=nums.size();

    if(n==0){
        return 0;
    }

    int maxlen=0;
    for(int i=0; i<n; i++){
        if(nums[i]==0){
            continue;
        }
        else{
            // nums[i]==1
            int j=i;
            while(j<n){
                if(nums[j]==1){
                    j++;
                }
                else{
                    break;
                }
            }
            maxlen=max(maxlen,j-i);
            i=j-1;
        }
    }
    return maxlen;
}

int max_ones_Ib(const vector<int> &nums){
    int n=nums.size();

    if(n==0){
        return 0;
    }

    int maxlen=0;
    int counter=0;
    for(int i=0; i<n; i++){
        if(nums[i]==1){
            counter++;
            if(counter>maxlen){
                maxlen=counter;
            }
        }
        else{
            if(counter>0){
                counter=0;
            }
        }
    }
    return maxlen;
}

// Q7. Maximum number of consecutive ones II
// you can flip atmost one 0

// main concept :
// ek aisa subarray ya ek aisi window jiske andar maximum bas ek hi zero ho
// window can have no zeros or window can have maximum one zero
int max_ones_IIa(const vector<int> &nums){
    int n=nums.size();
    
    if(n==0){
        return 0;
    }

    // defining a window 
    // window is from i to j-1
    // so initially window is empty
    // so initially window size=0
    int i=0;
    int j=0;

    int maxlen=0;

    int count_zeros=0; // count_zeros <= 1
    while(j<n){
        if(nums[j]==1){
            maxlen=max(maxlen,j-i+1); // j element window cha part ahe asa assume kela
            j++;
        }
        else{
            // when nums[j]==0
            if(count_zeros==0){
                count_zeros++;
                maxlen=max(maxlen,j-i+1); // j element window cha part ahe asa assume kela
                j++;
            }
            else{
                // when count_zeros>=1
                while(nums[i]==1){
                    i++;
                }
                count_zeros--;
                i++;  // removing the first occurance of 0 from the left side of the window
            }
        }
    }
    return maxlen;
}

int max_ones_IIb(const vector<int> &nums){
    int n=nums.size();

    if(n==0){
        return 0;
    }

    // defining an empty window with size = 0
    // the window is from i=0 to j-1=-1 -> empty
    int i=0;
    int j=0;
    int maxlen=0;

    int count_zeros=0; // count_zeros tracks the number of zeros in the sliding window 
    // Now in this question the sliding window can have atmost one 0s

    while(j<n){
        if(nums[j]==1){
            // whenever i encounter 1 ,whenever i found 1 on the jth index
            // i am going to include that 1 / element at jth index into the sliding window
            // Now the jth index with value 1 is unofficially included
            maxlen=max(maxlen,j-i+1);
            j++; // offially included 1 in the sliding window
        }
        else{
            // whenever i encounter 0 ,whenever i found 0 on the jth index
            // i will check how many 0s my sliding window already has

            if(count_zeros==0){
                // when my sliding window has no 0s
                // the number of 0s in my sliding window is zero
                // so in that case i can include the 0 on the jth index in my sliding window
                count_zeros++;  // increasing the count of zeros in the sliding window
                // Now the jth index with value 0 is unofficially included in the sliding window
                maxlen=max(maxlen,j-i+1);
                j++; // officially included 0 in the sliding window
            }
            else{
                // when my sliding window has atleast one 0s
                // count_zeros>=1
                // so in that case from the left side of the window i am going to remove the first occurance of zero 
                // left side of sliding window me jo pehla 0 hoga me use remove karunga 
                // aur is remove karne ke process me 1s bhi remove konge
                while(nums[i]==1){
                    i++;
                }
                // now i is pointing at 0 value
                count_zeros--; // decreasing the count of zeros in the sliding window
                i++; // first occurance of 0 from the left side of sliding window is offically excluded
            }
        }
    }
    return maxlen;
}

// Q8. Maximum number of consecutive ones III

// when you can flip atmost two 0s

// main concept :
// ek aisa subarray ya ek aisi window jiske andar maximum bas two 0s ho
// window can have 0s less than or equal to two
int max_ones_III2(const vector<int> &nums){
    int n=nums.size();
    
    if(n==0){
        return 0;
    }

    // defining a window from i=0 to j-1=-1 with size=0
    // the sliding window is empty
    int i=0;
    int j=0;
    int maxlen=0;

    int count_zeros=0; // count_zeros <= 1
    while(j<n){
        if(nums[j]==1){
            maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
            j++;
        }
        else{
            // when nums[j]==0
            if(count_zeros==0){
                count_zeros++;
                maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
                j++;
            }
            else if(count_zeros==1){
                count_zeros++;
                maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
                j++;
            }
            else{
                // when count_zeros>=2
                while(nums[i]==1){
                    i++;
                }
                count_zeros--;
                i++;  // removing the first occurance of 0 from the left side of the window
            }
        }
    }
    return maxlen;
}

// when you can flip atmost three 0s

// main concept :
// ek aisa subarray ya ek aisi window jiske andar maximum bas three 0s ho
// window can have 0s less than or equal to three
int max_ones_III3(const vector<int> &nums){
    int n=nums.size();
    
    if(n==0){
        return 0;
    }

    // defining a window from i=0 to j-1=-1 with size=0
    // the sliding window is empty
    int i=0;
    int j=0;
    int maxlen=0;

    int count_zeros=0; // count_zeros <= 1
    while(j<n){
        if(nums[j]==1){
            maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
            j++;
        }
        else{
            // when nums[j]==0
            if(count_zeros==0){
                count_zeros++;
                maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
                j++;
            }
            else if(count_zeros==1){
                count_zeros++;
                maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
                j++;
            }
            else if(count_zeros==2){
                count_zeros++;
                maxlen=max(maxlen,j-i+1); // jth element window cha part ahe asa assume kela / jth element la windiw madhe include kela
                j++;
            }
            else{
                // when count_zeros>=3
                while(nums[i]==1){
                    i++;
                }
                count_zeros--;
                i++;  // removing the first occurance of 0 from the left side of the window
            }
        }
    }
    return maxlen;
}

// Most Generic Approach
// when you can flip atmost k 0s

// main concept :
// ek aisa subarray ya ek aisi window jiske andar maximum bas k 0s ho
// window can have 0s less than or equal to k
int max_ones_III(const vector<int> &nums,int k){
    int n=nums.size();

    if(n==0){
        return 0;
    }

    // defining an empty window with size = 0
    // the window is from i=0 to j-1=-1 -> empty
    int i=0;
    int j=0;
    int maxlen=0;

    int count_zeros=0; // count_zeros tracks the number of zeros in the sliding window 
    // Now in this question the sliding window can have atmost k 0s

    while(j<n){
        if(nums[j]==1){
            // whenever i encounter 1 ,whenever i found 1 on the jth index
            // i am going to include that 1 / element at jth index into the sliding window
            maxlen=max(maxlen,j-i+1); // Now the jth index with value 1 is unofficially included
            j++; // officially included 1 in the sliding window
        }
        else{
            // whenever i encounter 0 ,whenever i found 0 on the jth index
            // i will check how many 0s my sliding window already has

            if(count_zeros<k){  // or count_zeros<=k-1
                // the number of 0s in my sliding window is less than k
                // so in that case i can include the 0 on the jth index in my sliding window
                count_zeros++;  // increasing the count of zeros in the sliding window
                maxlen=max(maxlen,j-i+1);  // Now the jth index with value 0 is unofficially included in the sliding window
                j++; // officially included 0 in the sliding window
            }
            else{
                // when my sliding window has number of zeros >= k
                // count_zeros>=k
                // so in that case from the left side of the window i am going to remove the first occurance of zero 
                // left side of sliding window me jo pehla 0 hoga me use remove karunga 
                // aur is remove karne ke process me 1s bhi remove honge
                while(nums[i]==1){
                    i++;
                }
                // now i is pointing at 0 value
                count_zeros--; // decreasing the count of zeros in the sliding window
                i++; // first occurance of 0 from the left side of sliding window is offically excluded
            }
        }
    }
    return maxlen;
}

int main(){
    vector<int> nums={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << max_ones_Ia(nums) << endl;
    cout << max_ones_Ib(nums) << endl;

    vector<int> nums1={0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1};
    cout << max_ones_IIa(nums1) << endl;
    cout << max_ones_IIb(nums1) << endl;

    cout << max_ones_III(nums1,1) << endl; // max one 0s
    cout << max_ones_III2(nums1) << endl; // max two 0s
    cout << max_ones_III(nums1,2) << endl; // max two 0s
}