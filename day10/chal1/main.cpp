#include <iostream>
#include <set>
using namespace std;

set<pair<int, int>> vis;

void recurse(vector<string> &mat, int r, int c, long &ans, int cur, string &str)
{
    if (vis.find({r, c}) != vis.end())
    {
        return;
    }
    vis.insert({r, c});
    if (str == "0123456789")
    {
        ans++;
    }
    // left
    if (c - 1 >= 0 and mat[r][c - 1] - '0' == cur + 1)
    {
        str.push_back(mat[r][c - 1]);
        recurse(mat, r, c - 1, ans, cur + 1, str);
        str.pop_back();
    }
    // right
    if (c + 1 < mat[r].size() and mat[r][c + 1] - '0' == cur + 1)
    {
        str.push_back(mat[r][c + 1]);
        recurse(mat, r, c + 1, ans, cur + 1, str);
        str.pop_back();
    }
    // top
    if (r - 1 >= 0 and mat[r - 1][c] - '0' == cur + 1)
    {
        str.push_back(mat[r - 1][c]);
        recurse(mat, r - 1, c, ans, cur + 1, str);
        str.pop_back();
    }
    // bottom
    if (r + 1 < mat.size() and mat[r + 1][c] - '0' == cur + 1)
    {
        str.push_back(mat[r + 1][c]);
        recurse(mat, r + 1, c, ans, cur + 1, str);
        str.pop_back();
    }
}

int main()
{
    int times = 57;
    vector<string> mat;
    for (int i = 0; i < times; i++)
    {
        string s;
        cin >> s;
        mat.push_back(s);
    }
    long ans = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == '0')
            {
                string str = "0";
                recurse(mat, i, j, ans, 0, str);
                vis.clear();
            }
        }
    }
    cout << ans << endl;
}
