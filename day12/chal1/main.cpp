#include <iostream>
using namespace std;

void dfs(vector<string> &mat, vector<vector<bool>> &vis, int r, int c, int &area, int &perimeter)
{
    area++;
    perimeter += 4;
    if (r + 1 < mat.size() and mat[r + 1][c] == mat[r][c])
    {
        perimeter--;
    }
    if (r - 1 >= 0 and mat[r - 1][c] == mat[r][c])
    {
        perimeter--;
    }
    if (c + 1 < mat[r].size() and mat[r][c + 1] == mat[r][c])
    {
        perimeter--;
    }
    if (c - 1 >= 0 and mat[r][c - 1] == mat[r][c])
    {
        perimeter--;
    }
    if (!vis[r][c])
    {
        vis[r][c] = true;
        if (c + 1 < mat[r].size() and mat[r][c + 1] == mat[r][c] and !vis[r][c + 1])
        {
            dfs(mat, vis, r, c + 1, area, perimeter);
        }
        if (r + 1 < mat.size() and mat[r + 1][c] == mat[r][c] and !vis[r + 1][c])
        {
            dfs(mat, vis, r + 1, c, area, perimeter);
        }
        if (c - 1 >= 0 and mat[r][c - 1] == mat[r][c] and !vis[r][c - 1])
        {
            dfs(mat, vis, r, c - 1, area, perimeter);
        }
        if (r - 1 >= 0 and mat[r - 1][c] == mat[r][c] and !vis[r - 1][c])
        {
            dfs(mat, vis, r - 1, c, area, perimeter);
        }
    }
}

int main()
{
    int times = 140;
    vector<string> mat;
    vector<vector<bool>> vis;
    for (int i = 0; i < times; i++)
    {
        string s;
        cin >> s;
        mat.push_back(s);
        vis.push_back(vector<bool>(s.length(), false));
    }
    long ans = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (!vis[i][j])
            {
                int area = 0;
                int perimeter = 0;
                dfs(mat, vis, i, j, area, perimeter);
                ans += (area * perimeter);
            }
        }
    }
    cout << "Total price: " << ans;
}