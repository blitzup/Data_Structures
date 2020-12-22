#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#define MAX 500
using namespace std;

int multiply(int a[], int a_size, int m)
{
    int mult = 0, carry = 0, length = 0;
    for (auto i = 0; i < a_size; i++)
    {
        mult = a[i] * m + carry;
        carry = mult / 10;
        a[i] = mult % 10;
        length++;
    }

    if (carry != 0)
    {
        string s = to_string(carry);
        reverse(s.begin(), s.end());
        int k = 0;
        for (auto i = length; i < length + s.size(); i++)
            a[i] = s[k] - '0';

        length += s.size();
    }

    return length;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1 || n == 0)
            cout << 1 << " ";

        else
        {

            int a[MAX];
            a[0] = 1;
            int length = 1;
            for (auto i = 2; i <= n; i++)
            {
                length = multiply(a, length, i);
            }

            int flag = 1;
            for (auto i = length - 1; i >= 0; i--)
            {
                // if (a[i] == 0 && flag)
                //     continue;
                flag = 0;
                cout << a[i];
            }
        }

        cout << endl;
    }
    return 0;
}