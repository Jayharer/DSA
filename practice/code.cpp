#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve(vector<int> arr, int index, int sum, vi res, vector<vector<int>> &ans)
{
    if (sum < 0)
        return;
    if (sum == 0)
    {
        ans.push_back(res);
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        vi curr = res;
        curr.push_back(arr[i]);
        solve(arr, i, sum - arr[i], curr, ans);
    }
    return;
}

vector<vector<int>> combSum(vector<int> &arr, int sum)
{
    vector<vector<int>> ans;
    vector<int> res;
    sort(arr.begin(), arr.end());
    solve(arr, 0, sum, res, ans);
    return ans;
}

#define pb push_back

std::vector<std::vector<int>> copyMatrix(const std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Create a new matrix with the same size as the original matrix
    std::vector<std::vector<int>> copiedMatrix(rows, std::vector<int>(cols));

    // Copy each element from the original matrix to the new matrix
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            copiedMatrix[i][j] = matrix[i][j];
        }
    }

    return copiedMatrix;
}

void solve(vector<vector<int>> mat, int row, vector<vector<int>> &ans, int n)
{
    if (row == n)
    {
        vector<int> res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == -1)
                    res.pb(0);
                else
                    res.pb(mat[i][j]);
        ans.pb(res);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (mat[row][col] == 0)
        {
            vector<vector<int>> nmat = copyMatrix(mat);
            nmat[row][col] = 1;
            // update cols
            for (int r = row + 1; r < n; r++)
                nmat[r][col] = -1;
            // update forward diagonal
            for (int r = row + 1, c = col + 1; r < n && c < n; r++, c++)
            {
                nmat[r][c] = -1;
            }
            // update backword diagonal
            for (int r = row + 1, c = col - 1; r < n && c >= 0; r++, c--)
            {
                nmat[r][c] = -1;
            }
            solve(nmat, row + 1, ans, n);
        }
    }
    return;
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(mat, 0, ans, n);
    return ans;
}