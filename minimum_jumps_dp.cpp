#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int jumps[n];
    jumps[0] = 0;

    for (auto i = 1; i < n; i++)
    {
        int globalmin = INT_MAX;
        if(arr[i] == 0 && i!=n-1) {
            jumps[i] = INT_MAX;
            continue;
        }
        
        for (auto j = 0; j < i; j++)
        {
            if(arr[j] + j >= i)
                globalmin = min(jumps[j]+1, globalmin);
        }

        jumps[i] = globalmin;
    }

    if(jumps[n-1] != INT_MAX && (arr[0]!=0 || n==1))
        return jumps[n-1];
    else return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (auto i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }

    return 0;
}