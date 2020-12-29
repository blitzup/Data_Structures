#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int findLongestConseqSubseq1(int a[], int N)
{
    sort(a, a + N);
    int max_size = 0, current_size = 1;
    for (auto i = 1; i < N; i++)
    {
        if (a[i] == a[i - 1] + 1)
            current_size++;
        else if (a[i] == a[i - 1])
            continue;
        else
        {
            max_size = max(max_size, current_size);
            current_size = 1;
        }
    }

    max_size = max(max_size, current_size);
    return max_size;
}

int findLongestConseqSubseq2(int a[], int N)
{

    unordered_set<int> s;
    int max_length = 0, length=0;
    for (auto i = 0; i < N; i++)
        s.insert(a[i]);

    for (auto i = 0; i < N; i++)
    {
        length = 0;
        if(s.find(a[i]-1) == s.end())
        {
            int j = a[i];
            while(s.find(j) != s.end())
                j++, length++;
        }

        max_length = max(max_length, length);
    }

    return max_length;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int a[N];
        for (auto i = 0; i < N; i++)
            cin >> a[i];

        int length = findLongestConseqSubseq2(a, N);
        cout << length << endl;
    }
    return 0;
}