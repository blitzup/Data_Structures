#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct element{
    int start_time, end_time, index;
};

bool compare(struct element a, struct element b)
{
    return (a.end_time < b.end_time);
}

void maxMeetings(int start[], int end[], int n)
{

    struct element c[n];
    for (auto i = 0; i < n; i++)
        c[i].start_time = start[i], c[i].end_time = end[i], c[i].index = i;
    stable_sort(c, c+n, compare);

    int end_completed = c[0].end_time;
    cout << c[0].index+1 << " ";
    for(auto i=1; i<n; i++)
    {
        if(c[i].start_time > end_completed) end_completed = c[i].end_time, cout << c[i].index+1 << " ";
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
        int start[n], end[n];
        for (auto i = 0; i < n; i++)
            cin >> start[i];
        for (auto i = 0; i < n; i++)
            cin >> end[i];

        maxMeetings(start, end, n);
    }
    return 0;
}