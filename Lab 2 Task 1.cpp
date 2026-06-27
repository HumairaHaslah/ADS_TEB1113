#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int> >& mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int row = 0, col = 0;
    int prev, curr;

    while (row < m && col < n)
    {
        if (row + 1 == m || col + 1 == n)
            break;

        prev = mat[row + 1][col];

        for (int i = col; i < n; i++)
        {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for (int i = row; i < m; i++)
        {
            curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        for (int i = n - 1; i >= col; i--)
        {
            curr = mat[m - 1][i];
            mat[m - 1][i] = prev;
            prev = curr;
        }
        m--;

        for (int i = m - 1; i >= row; i--)
        {
            curr = mat[i][col];
            mat[i][col] = prev;
            prev = curr;
        }
        col++;
    }
}

int main()
{
    vector<vector<int> > mat =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(mat);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
