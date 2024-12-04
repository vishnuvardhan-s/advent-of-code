#include <iostream>
using namespace std;
int main()
{
    int times = 140;
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
            if (mat[i][j] == 'A')
            {
                if (i - 1 >= 0 and j - 1 >= 0 and i + 1 < mat.size() and j + 1 < mat[i].size())
                {
                    if (mat[i - 1][j - 1] == 'M' and mat[i - 1][j + 1] == 'S' and mat[i + 1][j - 1] == 'M' and mat[i + 1][j + 1] == 'S')
                    {
                        ans++;
                    }
                    else if (mat[i - 1][j - 1] == 'S' and mat[i - 1][j + 1] == 'S' and mat[i + 1][j - 1] == 'M' and mat[i + 1][j + 1] == 'M')
                    {
                        ans++;
                    }
                    else if (mat[i - 1][j - 1] == 'M' and mat[i - 1][j + 1] == 'M' and mat[i + 1][j - 1] == 'S' and mat[i + 1][j + 1] == 'S')
                    {
                        ans++;
                    }
                    else if (mat[i - 1][j - 1] == 'S' and mat[i - 1][j + 1] == 'M' and mat[i + 1][j - 1] == 'S' and mat[i + 1][j + 1] == 'M')
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << "X-MAS count " << ans;
}