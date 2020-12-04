#include <iostream>
#include <vector>

using namespace std;

void rotate_cyclic(int *, int, int);

int main()
{

    int n, k;
    cin >> n;
    int a[n];
    for (auto i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;

    rotate_cyclic(a, k, n);

    for (auto i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

void rotate_cyclic(int a[], int k, int n)
{
    vector<int> store;
    k %= n;

    int store_index = k;
    for (auto i = n - store_index; i < n; i++)
        store.push_back(a[i]);

    for (auto i = n - 1; i >= 0; i--)
    {
        if (i >= store_index)
            a[i] = a[i - k];
        else
            a[i] = store[i];
    }
}