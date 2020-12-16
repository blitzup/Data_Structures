#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct element
{
    int first;
    int second;
};

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {

        sort(arr, arr + n);

        // for(auto i=0; i<n; i++) cout << arr[i] << " ";
        // cout << endl;
        set<int> s;
        for (auto i = 0; i < n; i++)
            s.insert(arr[i]);

        // set<int>::iterator it=s.begin();
        // for (; it!=s.end(); it++)
        //     cout << *it << " ";
        // cout << endl;

        int nodup_size = s.size();
        // cout << nodup_size << "*****";

        struct element count[nodup_size];
        int p = 0;
        for (auto i = 0; i < n; i++)
        {
            if (arr[i - 1] == arr[i] && i != 0)
                count[p - 1].second++;
            else
                count[p] = {arr[i], 1}, p++;
        }

        // for(auto i=0; i<nodup_size; i++) cout << count[i].first << " " << count[i].second << endl;
        int i = 0, j = nodup_size - 1, pair_count = 0;
        double half = double(k) / 2;
        int flag=1;
        while (i < j)
        {
            if (count[i].first == half && flag)
                pair_count += count[i].second/2, flag=0; 


            if (count[j].first == half && flag)
                pair_count += count[j].second/2, flag=0; 

            if (count[i].first + count[j].first == k)
                pair_count += count[i].second * count[j].second, i++, j--;
            else if (count[i].first + count[j].first > k)
                j--;
            else if (count[i].first + count[j].first < k)
                i++;


        }
        
        if(flag && count[i].first == half) pair_count += count[i].second/2, flag=0; 

        return pair_count;
    }

    int brute_count_pair(int arr[], int n, int k)
    {
        int count_pairs = 0;
        for (auto i = 0; i < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == k)
                {
                    cout << arr[i] << " " << arr[j] << endl;
                    count_pairs++;
                }
            }
        }

        return count_pairs;
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
        int arr[n];
        for (auto i = 0; i < n; i++)
            cin >> arr[i];
        int k;
        cin >> k;
        Solution ob;
        int pair_count = ob.getPairsCount(arr, n, k);
        // int pair_count = ob.brute_count_pair(arr, n, k);

        cout << pair_count << endl;
    }
    return 0;
}