#include <iostream>
#include <stdlib.h>

using namespace std;
int kthSmallest(int *, int, int, int);

int main()
{
    int testcases;
    cin >> testcases;

    while(testcases--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];
        
        for(int i=0; i<number_of_elements; i++)
            cin>>a[i];

        int k;
        cin >> k;
        cout << kthSmallest(a, 0, number_of_elements-1, k) << endl;
    }

    return 0;
}

int kthSmallest(int* a, int l, int r, int k)
{

    int *pivot = &a[r];

    int *p = &a[l], *q = &a[r - 1], temp = 0;
    int n = sizeof(a) / sizeof(a[0]);

    if (r < l)
        return a[k - 1];

    int range = r - l + 1;
    int num = rand() % range + l;

    temp = a[num];
    a[num] = *pivot;
    *pivot = temp;

    while (q >= p)
    {
        while ((*q > *pivot) && (q >= &a[0]))
            q--;
        while (*p < *pivot)
            p++;

        if (q > p)
        {
            temp = *p;
            *p = *q;
            *q = temp;
        }
    }

    temp = *p;
    *p = *pivot;
    *pivot = temp;

    int upperbound = p - &a[0] - 1, lowerbound = p - &a[0] + 1;
    if (k - 1 <= upperbound)
        return kthSmallest(a, l, upperbound, k);
    else
        return kthSmallest(a, lowerbound, r, k);
}

// int kthSmallest(int a[], int l, int r, int k) {
//     int temp=0, flag;

//     for(auto j=0; j<k; j++){
//         flag = 0;
//         for(auto i=r; i>l; i--){
//             if(a[i] < a[i-1]){
//                 temp = a[i-1];
//                 a[i-1] = a[i];
//                 a[i] = temp;
//                 flag = 1;
//             }
//         }

//         if(flag == 0) break;
//     }

//     return a[k-1];
// }