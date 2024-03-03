#include <bits/stdc++.h>
using namespace std;

double getDouble(string str)
{
    double res = 0.0;
    double p = 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        int num = str[i] - '0';
        res = num * p + res;
        p *= 10;
    }
    return res;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
    map<int, set<int>> adj_list;
    for (int i = 0; i < edges.size(); i++)
    {
        vector<int> edge = edges[i];
        adj_list[edge[0]].insert(edge[1]);
        adj_list[edge[1]].insert(edge[0]);
    }
    for (auto ele : adj_list)
    {
        cout << ele.first << ": ";
        for (auto val : adj_list[ele.first])
            cout << val << " ";
        cout << endl;
    }
}

/*
int main()
{
    vector<vector<int>> edges = {{0,1},{0,3},{1,2},{3,2}};
    map<int,set<int>> adj_list;
    for(int i=0; i< edges.size(); i++){
        vector<int> edge = edges[i];
        adj_list[edge[0]].insert(edge[1]);
    }
    for(auto ele: adj_list){
        cout << ele.first << ": ";
        for(auto val: adj_list[ele.first])
            cout << val << " ";
        cout << endl;
    }
}
*/

/*
int main()
{
    string str = "10/05/1992";
    string s1 = str.substr(0, 2);
    string s2 = str.substr(3, 2);
    int x = (s1[0] - '0') * 10 + (s1[1] - '0');
    int y = (s2[0] - '0') * 10 + (s2[1] - '0');
    cout << x << " " << y << endl;
}
*/
/*
int main()
{
    char x = '2';
    int y = x - 48;
    cout << y << endl;
}
*/

/*
int main()
{
    string str = "jayharer";
    string nstr = string(str.begin(), str.begin()+1);
    cout << nstr << endl;

}
*/

/*
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << (find(v.begin(), v.end(), 5) != v.end());
}
*/

/*
int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        string res = x<=7 ? "yes" : "no";
        cout << res << endl;
    }
}
*/
