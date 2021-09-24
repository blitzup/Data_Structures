#include <bits/stdc++.h>
using namespace std;

float median_of_2SortedArr(vector<int> a, vector<int> b)
{
    int count = 0, last = 0, i = 0, j = 0, n = a.size(), m = b.size(), now = 0;
    while(i<n && j<m && count <= (n+m)/2)
    {
        last = now;
        if(a[i] <= b[j]) now = a[i], i++;
        else now = b[j], j++;
        count++;
    }

    while(count <= (n+m)/2 && i<n)
        last = now, now = a[i++], count++;

    while(count <= (n+m)/2 && j<m)
        last = now, now = b[j++], count++;

    if((n+m)%2 == 0)
        return (last+now)/2.0;
    
    return now;

}

int main()
{
    vector<int> a, b;
    int n, m, k;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> k;
        a.push_back(k);
    }


    for(int i=0; i<m; i++)
    {
        cin >> k;
        b.push_back(k);
    }

    float medi = median_of_2SortedArr(a, b);
    cout << medi;
    return 0;
}
