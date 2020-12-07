#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int i=0, k=0, nums_size = nums.size();
        while(nums[i] != nums[nums[k]]) i=nums[i], k=nums[nums[k]];
        k=0, i=nums[i];
        while(nums[k] != nums[i]) k=nums[k], i=nums[i];
        return nums[i];
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto i=0; i<n; i++) cin >> nums[i];
    Solution ob;
    int duplicate = ob.findDuplicate(nums);
    cout << duplicate;

    return 0;
}