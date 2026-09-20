#include <algorithm>
#include <iostream>
#include <vector>
/*
Считаем динамику dp[i][j][u] - максимальный доступный счёт в клетке [i][j] со счетом ровно u.
Изначально  dp[0][0][0] = 0, ответ - максимальное значение dp[n - 1][m - 1][u]
по всем возможным стоимостям.
*/
using namespace std;
class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        size_t n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1e9)));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int u = 0; u <= k; u++)
                {
                    if (grid[i][j] == 0)
                    {
                        if (i > 0 && j == 0)
                        {
                            dp[i][j][u] = dp[i - 1][j][u];
                        }
                        else if (i == 0 && j > 0)
                        {
                            dp[i][j][u] = dp[i][j - 1][u];
                        }
                        else if (i > 0 && j > 0)
                        {
                            dp[i][j][u] = max(dp[i - 1][j][u], dp[i][j - 1][u]);
                        }
                    }
                    else
                    {
                        if (u == 0)
                        {
                            continue;
                        }
                        if (i > 0 && j == 0)
                        {
                            dp[i][j][u] = dp[i - 1][j][u - 1] + grid[i][j];
                        }
                        else if (i == 0 && j > 0)
                        {
                            dp[i][j][u] = dp[i][j - 1][u - 1] + grid[i][j];
                        }
                        else if (i > 0 && j > 0)
                        {
                            dp[i][j][u] =
                                max(dp[i - 1][j][u - 1], dp[i][j - 1][u - 1]) +
                                grid[i][j];
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int u = 0; u <= k; u++)
        {
            ans = max(ans, dp[n - 1][m - 1][u]);
        }
        return ans;
    }
};

int main()
{
    auto s = Solution();
    vector<vector<int>> grid(2);
    grid[0] = {0, 1};
    grid[1] = {2, 0};
    int k = 1;
    cout << s.maxPathScore(grid, k);
}
