#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one_variable_reverse(vector<int> array)
{
    int var = 0, array_size = array.size();

    for (auto i = 0; i < array_size / 2; i++)
    {
        var = array[i];
        array[i] = array[array_size - i - 1];
        array[array_size - i - 1] = var;
    }

    return array;
}

int main()
{
    vector<int> array;
    int array_size, input;
    cin >> array_size;
    for (auto i = 0; i < array_size; i++)
    {
        cin >> input;
        array.push_back(input);
    }

    vector<int> reverse_array(array_size);
    reverse_array = one_variable_reverse(array);

    //reverse(array.begin(), array.end());
    for (auto i : reverse_array)
    {
        cout << i << " ";
    }

    return 0;
}
