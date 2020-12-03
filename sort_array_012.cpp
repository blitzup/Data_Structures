#include <iostream>
#include <vector>

using namespace std;

void sort012(vector<int> &, int);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (auto i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort012(a, n);

        for (auto i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}

void sort012(vector<int> &a, int n)
{
    int count0 = 0, count1 = 0, count2 = 0;

    for (const int &i : a)
    {
        if (i == 0)
            count0++;
        else if (i == 1)
            count1++;
        else
            count2++;
    }

    int loop_count = 1;
    for (int i = 0; i < n; i++)
    {
        if (loop_count <= count0)
            a[i] = 0;
        else if (loop_count <= count0 + count1)
            a[i] = 1;
        else
            a[i] = 2;

        loop_count++;
    }


}