//Using just one binary search pass and recursion

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int index = binary_search(nums, 0, nums.size()-1, target);
        return index; 
    }

private:
    int binary_search(vector<int> &nums, int low, int high, int target)
    {
        if(low > high)
            return -1;

        int mid = low + (high - low)/2;
        if(nums[mid] == target)
            return mid;

        else if(nums[low] <= nums[mid])
        {
            if(nums[low] <= target && nums[mid] >= target)
                return binary_search(nums, low, mid - 1, target);

            return binary_search(nums, mid+1, high, target);
        }

        else
        {
            if(nums[mid] <= target && nums[high] >= target)
                return binary_search(nums, mid+1, high, target);

            return binary_search(nums, low, mid-1, target);
            
        }
    }
};

int main()
{
    Solution ob;
    int n, ele;
    cin >> n;
    vector<int> inp(n, 0), op;
    for (auto i = 0; i < n; i++)
    {
        cin >> ele;
        inp[i] = ele;
    }
    int target;
    cin >> target;
    int search_index = ob.search(inp, target);
    cout << search_index;
    return 0;
    

}