/*
void mergeSort(vector<int> &a, int n)
{
    if (n <= 1)
        return;
    int m = n / 2;
    vector<int> v1(a.begin(), a.begin() + m);
    vector<int> v2(a.begin() + m, a.end());
    mergeSort(v1, v1.size());
    mergeSort(v2, v2.size());
    vector<int> res = mergeArray(v1, v2);
    for (int i = 0; i < n; i++)
        a[i] = res[i];
}
*/

/*
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
        string original = str;
        str.erase(i, 1);
        solve(str, memo);
        str = original;
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
*/