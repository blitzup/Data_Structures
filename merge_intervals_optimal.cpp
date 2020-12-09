#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> final_intervals;
        sort(intervals.begin(), intervals.end(), comp);
        final_intervals.push_back(intervals[0]);
        int j = 0;
        for (auto i = 1; i < intervals.size(); i++)
        {
            if (final_intervals[j][1] < intervals[i][0])
                final_intervals.push_back(intervals[i]), j++;

            else final_intervals[j][1] = max(intervals[i][1], final_intervals[j][1]);

        }
        return final_intervals;
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
        vector<vector<int>> interval_inp(n, vector<int>(2, 0));
        for (auto i = 0; i < n; i++)
            cin >> interval_inp[i][0] >> interval_inp[i][1];

        Solution ob;
        vector<vector<int>> intervals = ob.merge(interval_inp);
        for (auto i = 0; i < intervals.size(); i++)
        {
            for (auto j = 0; j < 2; j++)
                cout << intervals[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}