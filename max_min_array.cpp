#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stdlib.h>

using namespace std;

pair<int, int> find_min_max(vector<int> array)
{

    int min_ = INT_MAX, max_ = INT_MIN, array_size = array.size();

    if (array_size == 1)
    {
        return pair<int, int>(array[0], array[0]);
    }

    if (array[0] > array[1])
    {
        min_ = array[1];
        max_ = array[0];
    }
    else
    {
        max_ = array[1];
        min_ = array[0];
    }

    for (auto i = 2; i < array_size - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            min_ = min(min_, array[i]);
            max_ = max(max_, array[i + 1]);
        }

        else
        {
            min_ = min(min_, array[i + 1]);
            max_ = max(max_, array[i]);
        }
    }

    pair<int, int> p(min_, max_);
    return p;
}

int main()
{

    vector<int> array;
    pair<int, int> p;
    int array_size, array_element;

    cin >> array_size;

    for (auto i = 0; i < array_size; i++)
    {
        cin >> array_element;
        array.push_back(array_element);
    }

    p = find_min_max(array);

    cout << p.first << " " << p.second;

    return 0;
}