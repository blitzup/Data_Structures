#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//could have also used SETS

int intersect_array(int *, int *, int, int);

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
        // vector<int> c;
        int total_size = 0;
        total_size = intersect_array(a, b, n, m);

        cout << total_size << endl;
    }

    // for(auto i=0; i<c.size(); i++) cout << c[i] << " ";
    return 0;
}

int intersect_array(int a[], int b[], int n, int m)
{
    unordered_map<int, int> umap;

    int c = 0;
    for (auto i = 0; i < n; i++)
    {
        if (umap.find(a[i]) == umap.end())
            umap.insert(pair<int, int>(a[i], 1));

        else
            ++umap[a[i]];
    }

    for (auto i = 0; i < m; i++)
    {
        if (umap.find(b[i]) == umap.end())
            umap.insert(pair<int, int>(b[i], 1));

        else
            ++umap[b[i]];
    }

    unordered_map<int, int>::iterator it = umap.begin();
    while (it != umap.end())
    {
        if ((it->second) % 2 == 0)
            c += (it->second) / 2;
        it++;
    }

    return c;
}