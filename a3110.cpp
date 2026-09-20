#include <iostream>
#include <string>

using namespace std;
// Считаем сумму по всем парам соседних символов.
class Solution
{
public:
    int scoreOfString(string s)
    {
        int sum = 0;
        for (size_t i = 1; i < s.size(); i++)
        {
            sum += abs(s[i] - s[i - 1]);
        }
        return sum;
    }
};

int main()
{
    auto s = Solution();
    cout << s.scoreOfString("hello");
}