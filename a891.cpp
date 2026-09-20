#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Отсортируем массив, так как исползуем все подмножества, то ответ это не изменит.
Элемент i в этом массиве будет 2^i максимальным и 2^(n - 1 - i) раз минимальным среди всех подмножеств.
Проходим по всем элементам и считаем сумму.
*/
class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0, n = nums.size();
        const long long p = 1e9 + 7;
        vector<long long> pows(n);
        pows[0] = 1;
        for (int i = 1; i < n; i++)
        {
            pows[i] = (pows[i - 1] * 2) % p;
        }
        for (int i = 0; i < n; i++)
        {
            ans += (nums[i] * pows[i] - nums[i] * pows[n - 1 - i]) % p;
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    auto s = Solution();
    cout << s.sumSubseqWidths(nums);
}