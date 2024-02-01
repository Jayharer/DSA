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
    string str = "73287686626876";
    double d = getDouble(str);
    cout << d << endl;
}

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
