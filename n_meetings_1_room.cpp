#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return (a[1] <= b[1]);
}

void maxMeetings(int start[], int end[], int n)
{

    vector<vector<int>> c(n);
    for (auto i = 0; i < n; i++)
        c[i] = vector<int>{start[i], end[i], i};
    sort(c.begin(), c.end(), compare);

    int end_completed = c[0][1];
    cout << c[0][2]+1 << " ";
    for(auto i=1; i<n; i++)
    {
        if(c[i][0] > end_completed) end_completed = c[i][1], cout << c[i][2]+1 << " ";
    }

    cout << endl;

    // for(auto i=0; i<n; i++) cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (auto i = 0; i < n; i++)
            cin >> start[i];
        for (auto i = 0; i < n; i++)
            cin >> end[i];

        maxMeetings(start, end, n);
    }
    return 0;
}