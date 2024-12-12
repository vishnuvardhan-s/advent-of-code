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

void visit(vector<string> &mat, int r1, int c1, int r2, int c2, unordered_set<pair<int, int>, hashFunction> &vis)
{
    // top right
    if (r2 < r1 and c1 < c2)
    {
        int rd = r1 - r2, cd = c2 - c1;
        int nr1 = r1 + rd, nc1 = c1 - cd;
        int nr2 = r2 - rd, nc2 = c2 + cd;
        if (nr1 < mat.size() and nc1 >= 0)
        {

            vis.insert({nr1, nc1});
        }
        if (nr2 >= 0 and nc2 < mat[r2].size())
        {
            vis.insert({nr2, nc2});
        }
    }
    // top left
    if (r2 < r1 and c2 < c1)
    {
        int rd = r1 - r2, cd = c1 - c2;
        int nr1 = r1 + rd, nc1 = c1 + cd;
        int nr2 = r2 - rd, nc2 = c2 - cd;
        if (nr1 < mat.size() and nc1 < mat[r1].size())
        {
            vis.insert({nr1, nc1});
        }
        if (nr2 >= 0 and nc2 >= 0)
        {
            vis.insert({nr2, nc2});
        }
    }
}

int main()
{
    int times = 50;
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
            if (mat[i][j] != '.')
            {
                for (int ii = 0; ii < mat.size(); ii++)
                {
                    for (int jj = 0; jj < mat[ii].size(); jj++)
                    {
                        if (ii == i and jj == j)
                        {
                            continue;
                        }
                        if (mat[i][j] == mat[ii][jj])
                        {
                            visit(mat, i, j, ii, jj, vis);
                        }
                    }
                }
            }
        }
    }
    cout << "Unique locations: " << vis.size();
}