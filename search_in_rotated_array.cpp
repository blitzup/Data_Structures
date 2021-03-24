//First pivot is found and array is divided in 2 subparts on each side of pivot. Target element is
//found both the arrays
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int low = 0, high = nums.size() - 1, mid, pivot = -1, start = nums[0], search_ind = -1;

        do
        {
            mid = low + (high - low) / 2;

            if (mid != 0)
            {
                if (nums[mid] < nums[mid - 1])
                {
                    pivot = mid;
                    break;
                }

                else if (nums[mid] > start)
                {
                    low = mid + 1;
                }

                else
                {
                    high = mid - 1;
                }
            }

            else if (mid == 0)
            {

                if (high == 0)
                {
                    if (nums[0] == target)
                        return 0;
                    else
                        return -1;
                }

                if (nums[mid] < nums[mid + 1])
                    pivot = mid;
                else
                    pivot = mid + 1;

                break;
            }

        } while (high >= low);

        if (pivot == -1)
            pivot = 0;

        vector<int>::iterator it;

        if (pivot == 0)
        {
            it = lower_bound(nums.begin(), nums.end(), target);
        }

        else
        {
            if (target == start)
                it = nums.begin();

            else if (target <= start)
            {
                low = pivot;
                it = lower_bound(nums.begin() + pivot, nums.end(), target);
            }

            else if (target >= start)
            {
                high = pivot;
                it = lower_bound(nums.begin(), nums.begin() + pivot, target);
            }
        }

        if (it != nums.end() && *it == target)
            search_ind = it - nums.begin();

        return search_ind;
    }
};

int main()
{
    Solution ob;
    int n;
    cin >> n;
    vector<int> inp(n, 0), op;
    for (auto i = 0; i < n; i++)
        cin >> inp[i];
    int target;
    cin >> target;
    int search_index = ob.search(inp, target);
    cout << search_index;
    return 0;
}