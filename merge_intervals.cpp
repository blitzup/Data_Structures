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
        vector<vector<int>>::iterator it = intervals.begin();
        while (it != intervals.end())
        {
            // cout << (*it)[0] << "  ********** " << endl;
            if (it+1 != intervals.end() && (*it)[1] >= (*(it + 1))[1])
            {
                // intervals.erase(it + 1);
                vector<int> push_interval{(*it)[0], (*it)[1]};
                final_intervals.push_back(push_interval);

                if (it + 1 == intervals.end())
                    it++;
                else
                    it += 2;
            }

            else if (it+1 != intervals.end() && ((*it)[1] < (*(it + 1))[1]) && ((*it)[1] >= (*(it + 1))[0]))
            {
                vector<int> push_interval{(*it)[0], (*(it + 1))[1]};
                final_intervals.push_back(push_interval);
                if (it + 1 == intervals.end())
                    it++;
                else
                    it += 2;
                // (*it)[1] = (*(it + 1))[1];
                // intervals.erase(it + 1);
            }

            else
            {
                vector<int> push_interval{(*it)[0], (*it)[1]};
                final_intervals.push_back(push_interval);
                it++;
            }
        }
        if(final_intervals.size() != intervals.size()){
            vector<vector<int>> final_intervals2 = merge(final_intervals);
            return final_intervals2;
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