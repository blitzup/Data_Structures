#include <algorithm>
#include <iostream>

using namespace std;
//User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *a, int n)
    {

        long long max_val = 0, min_val = 0;
        long long maxproduct = a[0];
        for (auto i = 0; i < n; i++)
        {
            if (a[i] < 0)
                swap(max_val, min_val);
            // max_val = max(a[i], a[i] * max_val);
            if (a[i] > a[i] * max_val)
                max_val = a[i];
            else
                max_val = a[i] * max_val;
            // min_val = min(a[i], a[i] * min_val);
            if (a[i] < a[i] * min_val)
                min_val = a[i];
            else
                min_val = a[i] * min_val;

            // maxproduct = max(maxproduct, max_val);

            if (max_val > maxproduct)
                maxproduct = max_val;
        }

        return maxproduct;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (auto i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        long long maxProduct = ob.maxProduct(a, n);
        cout << maxProduct << endl;
    }
    return 0;
}