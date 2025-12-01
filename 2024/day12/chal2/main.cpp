#include <iostream>
#include <set>
using namespace std;

void dfs(vector<string> &mat, vector<vector<bool>> &vis, int r, int c, int &area, set<pair<int, int>> &region)
{
    region.insert({r, c});
    area++;
    if (!vis[r][c])
    {
        vis[r][c] = true;
        if (c + 1 < mat[r].size() and mat[r][c + 1] == mat[r][c] and !vis[r][c + 1])
        {
            dfs(mat, vis, r, c + 1, area, region);
        }
        if (r + 1 < mat.size() and mat[r + 1][c] == mat[r][c] and !vis[r + 1][c])
        {
            dfs(mat, vis, r + 1, c, area, region);
        }
        if (c - 1 >= 0 and mat[r][c - 1] == mat[r][c] and !vis[r][c - 1])
        {
            dfs(mat, vis, r, c - 1, area, region);
        }
        if (r - 1 >= 0 and mat[r - 1][c] == mat[r][c] and !vis[r - 1][c])
        {
            dfs(mat, vis, r - 1, c, area, region);
        }
    }
}

int sides(set<pair<int, int>> &region)
{
    set<pair<double, double>> corners;
    for (auto it : region)
    {
        int r = it.first, c = it.second;
        corners.insert({r - 0.5, c - 0.5});
        corners.insert({r + 0.5, c - 0.5});
        corners.insert({r + 0.5, c + 0.5});
        corners.insert({r - 0.5, c + 0.5});
    }
    int s = 0;
    for (auto it : corners)
    {
        double r = it.first, c = it.second;
        vector<bool> config;
        config.push_back(region.find({r - 0.5, c - 0.5}) != region.end());
        config.push_back(region.find({r + 0.5, c - 0.5}) != region.end());
        config.push_back(region.find({r + 0.5, c + 0.5}) != region.end());
        config.push_back(region.find({r - 0.5, c + 0.5}) != region.end());
        int matches = count(config.begin(), config.end(), true);
        vector<bool> config1 = {false, true, false, true};
        vector<bool> config2 = {true, false, true, false};
        if (matches == 2)
        {
            if (config == config1 or config == config2)
            {
                s += 2;
            }
        }
        else if (matches == 1 or matches == 3)
        {
            s += 1;
        }
    }
    return s;
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
                set<pair<int, int>> region;
                int area = 0;
                dfs(mat, vis, i, j, area, region);
                ans += (area * sides(region));
            }
        }
    }
    cout << "Total price: " << ans;
}