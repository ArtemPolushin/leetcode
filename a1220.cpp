#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Считаем динамику dp, где dp[0][i] - количество строк длины i+1, оканчивающихся на символ 'a'.
Аналогично, dp[1] - 'e', dp[2] - 'i', dp[3] - 'o', dp[4] - 'u'
Ответ: сумма по всем dp[i][n-1]
*/
class Solution
{
public:
    int countVowelPermutation(int n)
    {
        const int p = 1e9 + 7;
        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        for (int i = 0; i < 5; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[4][i - 1]) % p;
            dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % p;
            dp[2][i] = (dp[1][i - 1] + dp[3][i - 1]) % p;
            dp[3][i] = dp[2][i - 1];
            dp[4][i] = (dp[2][i - 1] + dp[3][i - 1]) % p;
        }
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            ans = (ans + dp[i][n - 1]) % p;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    auto s = Solution();
    cout << s.countVowelPermutation(n);
}
