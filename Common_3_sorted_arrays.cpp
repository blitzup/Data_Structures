#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int i = 0, j = 0, k = 0, result_index = 0;
        vector<int> result;
        while (i < n1 && j < n2 && k < n3)
        {

            if (A[i] == B[j] && B[j] == C[k])
            {
                if (result_index != 0 && A[i] == result[result_index - 1])
                {
                    i++, j++, k++;
                    continue;
                }
                else
                    result.push_back(A[i]), i++, j++, k++, result_index++;
            }

            else
            {
                if (A[i] > B[j])
                {
                    if (A[i] > C[k])
                    {
                        while (B[j] < A[i])
                            j++;
                        while (C[k] < A[i])
                            k++;
                    }

                    else
                    {
                        while (B[j] < C[k])
                            j++;
                        while (A[i] < C[k])
                            i++;
                    }
                }

                else
                {
                    if (B[j] > C[k])
                    {
                        while (A[i] < B[j])
                            i++;
                        while (C[k] < B[j])
                            k++;
                    }

                    else
                    {
                        while (B[j] < C[k])
                            j++;
                        while (A[i] < C[k])
                            i++;
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1], B[n2], C[n3];
        for (auto i = 0; i < n1; i++)
            cin >> A[i];
        for (auto i = 0; i < n2; i++)
            cin >> B[i];
        for (auto i = 0; i < n3; i++)
            cin >> C[i];
        Solution ob;
        vector<int> result = ob.commonElements(A, B, C, n1, n2, n3);

        for (auto const &i : result)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}