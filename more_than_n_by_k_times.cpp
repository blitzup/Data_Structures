#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<int> sorted(vector<int> arr, int check_count)
{
    sort(arr.begin(), arr.end());
    vector<int> result;
    int count = 1;
    for (auto i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        else
        {
            if (count >= check_count)
                result.push_back(arr[i - 1]);
            count = 1;
        }
    }

    return result;
}

vector<int> count(vector<int> arr, int check_count)
{
    vector<int> result;
    unordered_map<int, int> umap;
    for (auto const &ele : arr)
        umap[ele]++;

    unordered_map<int, int>::iterator it = umap.begin();
    for (; it != umap.end(); it++)
    {
        if (it->second >= check_count)
            result.push_back(it->first);
    }

    return result;
}

vector<int> k_minus_1_array(vector<int> arr, int check_count, int k)
{
    int entered = 0;
    vector<int> result;
    unordered_map<int, int> probable_ele(k - 1);
    unordered_map<int, int>::iterator it;
    for (auto const &ele : arr)
    {
        if (probable_ele.find(ele) == probable_ele.end())
        {
            if (entered < k - 1)
                probable_ele[ele]++;
            else
            {
                for (it = probable_ele.begin(); it != probable_ele.end(); it++)
                {
                    it->second--;
                    if (it->second == 0)
                        probable_ele.erase(it), entered--;
                }
            }
        }

        else
            probable_ele[ele]++;
    }

    for (it = probable_ele.begin(); it != probable_ele.end(); it++)
    {
        if (it->second >= check_count)
            result.push_back(it->first);
    }

    return result;
}

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int check_count = floor(n / k) + 1;
    // vector<int> result = count(arr, check_count);
    vector<int> result = k_minus_1_array(arr, check_count, k);

    if (result.size() == 0)
        cout << -1 << " ";

    else
    {
        for (const int &ele : result)
            cout << ele << " ";
    }

    return 0;
}