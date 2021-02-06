#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {

        // if(r==1 && c==1) return vector<int>{matrix[0][0]};
        vector<int> result;
        pair<int, int> p1(0, 0), p2(0, c - 1), p3(r - 1, c - 1), p4(r - 1, 0), p1_old(0, 0);
        int total_elements = r * c;
        int i = 0, j = 0;
        int traversed_ele = 0;

        while (total_elements > traversed_ele)
        {
            if (p1 == p2 && p3 == p4 && p1 == p4)
            {
                traversed_ele++;
                result.push_back(matrix[i][j]);
                break;
            }

            if (p1 == p4 && p2 == p3)
            {
                i = p1.first;
                j = p1.second;

                while (j != p2.second)
                {
                    traversed_ele++;
                    result.push_back(matrix[i][j]);
                    // cout << matrix[i][j] << " " << "1st" << "  ";
                    j++;
                }
                result.push_back(matrix[i][j]);

                break;
            }

            if (p1 == p2 && p3 == p4)
            {
                i = p1.first;
                j = p1.second;

                while (i != p3.first)
                {
                    traversed_ele++;
                    result.push_back(matrix[i][j]);
                    // cout << matrix[i][j] << " " << "1st" << "  ";
                    i++;
                }
                result.push_back(matrix[i][j]);

                break;
            }

            if (i == p1.first && j == p1.second)
            {
                p1_old = p1;
                p1.first = i + 1;
                p1.second = j + 1;
                while (j != p2.second)
                {
                    traversed_ele++;
                    result.push_back(matrix[i][j]);
                    // cout << matrix[i][j] << " " << "1st" << "  ";
                    j++;
                }
            }

            if (i == p2.first && j == p2.second)
            {
                p2.first = i + 1;
                p2.second = j - 1;
                while (i != p3.first)
                {
                    traversed_ele++;
                    result.push_back(matrix[i][j]);
                    // cout << matrix[i][j] << " " << "2nd" << "  ";
                    i++;
                }
            }

            if (i == p3.first && j == p3.second)
            {
                p3.first = i - 1;
                p3.second = j - 1;
                while (j != p4.second)
                {
                    traversed_ele++;
                    result.push_back(matrix[i][j]);

                    // cout << matrix[i][j] << " " << "3rd" << "  ";

                    j--;
                }
            }

            if (i == p4.first && j == p4.second)
            {
                p4.first = i - 1;
                p4.second = j + 1;
                while (i != p1_old.first)
                {
                    traversed_ele++;
                    result.push_back(matrix[i][j]);
                    // cout << matrix[i][j] << " " << "4th" << "  ";

                    i--;
                }

                i = p1.first;
                j = p1.second;
                // break;
            }
        }

        return result;
    }
};

int main()
{

    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));

    for (auto i = 0; i < r; i++)
    {
        for (auto j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution ob;
    vector<int> spiral_traversal;
    spiral_traversal = ob.spirallyTraverse(matrix, r, c);

    for (auto ele : spiral_traversal)
        cout << ele << " ";

    return 0;
}