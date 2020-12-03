#include <iostream>
#include <vector>

using namespace std;
void negative_element_oneside(vector<int> &);

int main()
{
    int array_size;
    cin >> array_size;
    vector<int> array(array_size);

    for (int i = 0; i < array_size; i++)
        cin >> array[i];
    negative_element_oneside(array);

    for (int i = 0; i < array_size; i++)
        cout << array[i] << " ";

    return 0;
}

void negative_element_oneside(vector<int> &vec)
{
    vector<int>::iterator start = vec.begin(), last = vec.end();
    int temp = 0;
    while (last > start)
    {
        while ((*start < 0) && (start != vec.end()))
            start++;
        while ((*last >= 0) && (last != vec.begin()-1))
            last--;

        if (last > start)
            swap(*start, *last);
    }
}
