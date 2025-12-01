#include <iostream>
#include <unordered_set>
using namespace std;

struct hashFunction
{
    size_t operator()(const pair<int, int> &x) const
    {
        return x.first ^ x.second;
    }
};

void recurse(vector<string> &mat, unordered_set<pair<int, int>, hashFunction> &vis, int i, int j, char dir)
{
    if (mat[i][j] == '.')
    {
        vis.insert({i, j});
    }
    if (dir == '^')
    {
        if (i - 1 >= 0 and mat[i - 1][j] == '.')
        {
            recurse(mat, vis, i - 1, j, '^');
        }
        if (i - 1 >= 0 and j + 1 < mat[i].size() and mat[i - 1][j] == '#')
        {
            recurse(mat, vis, i, j + 1, '>');
        }
    }
    else if (dir == 'v')
    {
        if (i + 1 < mat.size() and mat[i + 1][j] == '.')
        {
            recurse(mat, vis, i + 1, j, 'v');
        }
        if (i + 1 < mat.size() and j - 1 >= 0 and mat[i + 1][j] == '#')
        {
            recurse(mat, vis, i, j - 1, '<');
        }
    }
    else if (dir == '>')
    {
        if (j + 1 < mat[i].size() and mat[i][j + 1] == '.')
        {
            recurse(mat, vis, i, j + 1, '>');
        }
        if (j + 1 < mat[i].size() and i + 1 < mat.size() and mat[i][j + 1] == '#')
        {
            recurse(mat, vis, i, j, 'v');
        }
    }
    else if (dir == '<')
    {
        if (j - 1 >= 0 and mat[i][j - 1] == '.')
        {
            recurse(mat, vis, i, j - 1, '<');
        }
        if (j - 1 >= 0 and i - 1 >= 0 and mat[i][j - 1] == '#')
        {
            recurse(mat, vis, i - 1, j, '^');
        }
    }
}

int main()
{
    int times = 130;
    vector<string> mat;
    while (times--)
    {
        string s;
        cin >> s;
        mat.push_back(s);
    }
    unordered_set<pair<int, int>, hashFunction> vis;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == '^')
            {
                mat[i][j] = '.';
                recurse(mat, vis, i, j, '^');
            }
        }
    }
    cout << "Distinct positions visited: " << vis.size();
}