#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int a[], int n)
{

    int sum = 0, max = INT_MIN;
    for (auto i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > max)
            max = sum;

        if (sum <= 0)
            sum = 0;
    }
    
    return max;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(auto i=0; i<n; i++) cin >> a[i];

        cout << maxSubarraySum(a, n) << endl;
    }

    return 0;
}