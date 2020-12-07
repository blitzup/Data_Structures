#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    //vector<long long int> visited(n, 0);
    int visited[n];
    for (auto z = 0; z < n; z++)
        visited[n] = 0;

    int jumps = 0, k = 0;

    if (arr[0] == 0)
        return -1;

    if (n == 1)
        return 0;

    for (auto i = 0; i < n; i += k)
    {

        int maximum = arr[i], maxindex = i;
        for (auto y = i; y > i - k; y--)
        {
            if ((arr[y] + y) > (maximum + maxindex))
            {
                maxindex = y;
                maximum = arr[y];
            }
        }

        if (maxindex < i)
        {
            k = maxindex - i;
            continue;
        }

        visited[i] = 1;

        int index;
        if (arr[i] + i >= n - 1)
            index = n - 1;
        else
            index = arr[i] + i;
        if (arr[index] != 0 || index == n - 1)
        {
            k = arr[i];
            jumps++;

            if (i + k >= n - 1)
                return jumps;
        }

        else
        {
            int j = index - 1;
            while ((j >= 0) && ((visited[j] == 1) || (arr[j] == 0)))
            {
                j--;
                if (visited[j] == 1)
                    jumps--;

                if (j == 0)
                    return -1;
            }

            if (j == 0)
                return -1;

            k = j - i;
            jumps++;
        }
    }
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