#include <iostream>
using namespace std;

void rearrange(int a[], int n)
{
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        while (a[i] >= 0 && i < n)
            i++;

        j = i + 1;
        while (a[j] < 0 && j < n)
            j++;

        if (j < n && i < n)
            swap(a[i], a[j]);
    }

    i = 1, j = n-1;

    while(i<j)
    {
        if(a[i] >= 0 && a[j] < 0) swap(a[i], a[j]), i+=2, j--;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (auto i = 0; i < n; i++)
            cin >> a[i];

        rearrange(a, n);
        for (auto i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}