#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    void insertion_sort(int a[], int n, int pos)
    {
        int element = a[pos], i = pos + 1, flag = 0;
        while (i < n && a[i] < element)
        {
            a[i - 1] = a[i];
            i++;
            flag = 1;
        }
        if (flag)
            a[i - 1] = element;
    }

    void maintain_order(int a[], int b[], int n, int m)
    {
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (b[j] < a[i])
            {
                swap(a[i], b[j]);
                insertion_sort(b, m, j);
            }
            i++;
        }
    }

    void gap_algorithm(int a[], int b[], int n, int m)
    {
        int gap = ceil(double(n + m) / 2);
        while (gap >= 1)
        {
            int p = 0, q = 0, flaga = 0, flagb = 0, traversed_b = 0;

            if (gap >= n)
            {
                q = gap % n, flagb = 1;
                traversed_b = q;
            }
            else
                q = gap;

            while (traversed_b < m)
            {
                if (flaga == 1 && flagb == 1)
                {
                    if (b[p] > b[q])
                        swap(b[p], b[q]);
                    p++, q++;
                    traversed_b++;
                }

                else if (flaga == 0 && flagb == 1)
                {
                    if (a[p] > b[q])
                        swap(a[p], b[q]);
                    p++, q++;
                    if (p >= n)
                        flaga = 1, p %= n;
                    traversed_b++;
                }

                else if (flaga == 0 && flagb == 0)
                {
                    if (a[p] > a[q])
                        swap(a[p], a[q]);
                    p++, q++;
                    if (q >= n)
                        flagb = 1, q %= n;
                }
            }
            if(gap > 1) gap = ceil(double(gap)/2);
            else gap = 0;
        }
    }

    void merge(int arr1[], int arr2[], int n, int m)
    {
        // maintain_order(arr1, arr2, n, m);
        gap_algorithm(arr1, arr2, n, m);
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (auto i = 0; i < n; i++)
            cin >> a[i];
        for (auto i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        ob.merge(a, b, n, m);

        for (auto i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;

        for (auto i = 0; i < m; i++)
            cout << b[i] << " ";

        cout << "\n";
    }

    return 0;
}