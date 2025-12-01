#include <iostream>
using namespace std;

string match = "XMAS";

bool right(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int jj = j; jj < mat[i].size(); jj++)
    {
        if (mat[i][jj] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool left(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int jj = j; jj >= 0; jj--)
    {
        if (mat[i][jj] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool down(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int ii = i; ii < mat.size(); ii++)
    {
        if (mat[ii][j] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool up(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int ii = i; ii >= 0; ii--)
    {
        if (mat[ii][j] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool upleft(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int ii = i, jj = j; ii >= 0 and jj >= 0; ii--, jj--)
    {
        if (mat[ii][jj] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool upright(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int ii = i, jj = j; ii >= 0 and jj < mat[i].size(); ii--, jj++)
    {
        if (mat[ii][jj] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool downleft(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int ii = i, jj = j; ii < mat.size() and jj >= 0; ii++, jj--)
    {
        if (mat[ii][jj] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

bool downright(vector<string> &mat, int i, int j)
{
    int k = 0;
    for (int ii = i, jj = j; ii < mat.size() and jj < mat[i].size(); ii++, jj++)
    {
        if (mat[ii][jj] == match[k])
        {
            k++;
            if (k == 4)
                return true;
        }
        else
        {
            return false;
        }
    }
    return k == match.size();
}

int main()
{
    vector<string> mat;
    int times = 140;
    while (times--)
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
            if (mat[i][j] == 'X')
            {
                ans += right(mat, i, j);
                ans += left(mat, i, j);
                ans += down(mat, i, j);
                ans += up(mat, i, j);
                ans += upleft(mat, i, j);
                ans += upright(mat, i, j);
                ans += downleft(mat, i, j);
                ans += downright(mat, i, j);
            }
        }
    }
    cout << "XMAS count " << ans;
}