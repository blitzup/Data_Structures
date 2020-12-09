#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int nums_size =  nums.size();
        int max_seen = nums[nums_size - 1], min_gt = INT_MAX, min_pos = 0;
        int flag = 0;
        // int max_count = 1, max_pos = nums_size - 1;
        
        for(auto i=nums_size-2; i>=0; i--){
            if(nums[i]>=max_seen) max_seen = nums[i];
            else{
                flag = 1;
                min_pos = i+1, min_gt = nums[i+1];
                for(auto j=i+2; j<=nums_size - 1; j++){
                    if(nums[j]<min_gt && nums[j]>nums[i]) min_gt = nums[j], min_pos = j;
                }
                
                swap(nums[i], nums[min_pos]);
                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        
        if(flag == 0) sort(nums.begin(), nums.end());
    }
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto i = 0; i < n; i++) cin >> nums[i];
        Solution ob;
        ob.nextPermutation(nums);
        for (auto i = 0; i < n; i++) cout << nums[i] << " ";
        cout << endl;
    }
    return 0;
}