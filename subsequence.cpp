#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void solve(string str, map<string, string> &memo)
{
    int n = str.size();
    if (memo.count(str))
        return;
    memo[str] = str;
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string s1 = string(str.begin(), str.begin() + i);
        string s2 = string(str.begin() + i + 1, str.end());
        solve(s1 + s2, memo);
    }
}

int main()
{
    string str = "act";
    map<string, string> memo;
    solve(str, memo);
    for (auto ele : memo)
    {
        cout << ele.first << " ";
    }
    cout << memo.size() << endl;
}