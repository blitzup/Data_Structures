#include <iostream>
#define max 5000
using namespace std;

int multiply(int a[], int length, int m)
{
    int final_length = 0, mult = 0, carry = 0, i;
    for (i = 0; i < length; i++)
    {
        mult = a[i]*m + carry;
        a[i] = mult % 10;
        carry = mult / 10;
        final_length++;
    }

    while(carry)
    {
        a[i] = carry % 10;
        carry = carry / 10;
        final_length++;
        i++;
    }

    return final_length;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[max];
        a[0] = 1;
        int length = 1;
        for (auto i = 2; i <= n; i++)
            length = multiply(a, length, i);

        for (auto i = length - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }

    return 0;
}