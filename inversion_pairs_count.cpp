// while dividing the array with odd length make sure that
// the left side length is smaller than equal to the right side

//check whether above statement true.
#include <bits/stdc++.h>
using namespace std;

long long int merge_arrays(long long int arr[], long long int lb, long long int mid, long long int ub)
{
    long long int i = lb, j = mid + 1, count = 0, b[ub + 1], k = 0;
    while (i <= mid && j <= ub)
    {
        if (arr[i] > arr[j])
            count += mid - i + 1, b[k++] = arr[j++];
        else
            b[k++] = arr[i++];
    }

    while (i <= mid)
        b[k++] = arr[i++];
    while (j <= ub)
        b[k++] = arr[j++];

    k = 0;
    for (auto i = lb; i <= ub; i++)
        arr[i] = b[k++];

    return count;
}

long long int merge_sort(long long int arr[], long long int lb, long long int ub)
{

    long long int count = 0, count1 = 0, count2 = 0;

    if (lb < ub)
    {
        long long int mid = (lb + ub - 1) / 2;
        count1 = merge_sort(arr, lb, mid);
        count2 = merge_sort(arr, mid + 1, ub);
        count = merge_arrays(arr, lb, mid, ub);
    }

    return count1 + count2 + count;
}

long long int inversionCount(long long arr[], long long N)
{
    long long int count = merge_sort(arr, 0, N - 1);
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--){
        long long int n;
        cin >> n;
        long long int arr[n];
        for(auto i=0; i<n; i++) cin >> arr[i];

        long long int inversion_pairs = inversionCount(arr, n);
        cout << inversion_pairs << endl;
    }

    return 0;
}