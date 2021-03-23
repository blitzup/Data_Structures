#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> subarraySum(int arr[], int n, int s){
        
        int curr_sum = 0, j = 0, start = 0, end = n - 1;
        vector<int> ans(2, -1);
        for(auto i = 0; i<n; i++)
        {
            if(arr[i] == s)
            {
                ans = {i+1, i+1};
                return ans;

            }
                
            curr_sum += arr[i];
            while(curr_sum > s && j < i-1)
            {
                curr_sum-=arr[j];
                j++;
            }
            
            if(curr_sum == s)
            {
                ans = {j+1, i+1}  ;                              
                return ans;
            }
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        
        int arr[n];
        for(auto i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for(auto i =0; i<res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }
    return 0;
}