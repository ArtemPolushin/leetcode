#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Рекурсивно строим все перестановки, поддерживая массив использованных чисел used и текущую перестановку cur.
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> cur, used;
    vector<vector<int>> permute(vector<int> &nums)
    {
        used.resize(nums.size(), 0);
        func(nums);
        return res;
    }
    void func(const vector<int> &nums)
    {
        if (cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                cur.push_back(nums[i]);
                func(nums);
                cur.pop_back();
                used[i] = 0;
            }
        }
    }
};

int main()
{
    auto s = Solution();
    vector<int> nums{1, 2, 3};
    auto r = s.permute(nums);
    for (int i = 0; i < r.size(); i++)
    {
        for (auto it : r[i])
        {
            cout << it << ' ';
        }
        cout << '\n';
    }
}
