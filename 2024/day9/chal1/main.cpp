#include <iostream>
using namespace std;

bool ok(vector<long long> &blocks, long free_space)
{
    int j = blocks.size() - 1, c = 0;
    while (blocks[j] == -1)
    {
        j--;
        c++;
    }
    return c == free_space;
}

int main()
{
    string s;
    cin >> s;
    long long files = 0;
    vector<long long> blocks;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
        {
            vector<long long> brr(s[i] - '0', files);
            blocks.insert(blocks.end(), brr.begin(), brr.end());
            files++;
        }
        else
        {
            vector<long long> brr(s[i] - '0', -1);
            blocks.insert(blocks.end(), brr.begin(), brr.end());
        }
    }
    int i = 0, j = blocks.size() - 1;
    long long free_space = count(blocks.begin(), blocks.end(), -1);
    while (!ok(blocks, free_space))
    {
        while (blocks[i] != -1)
        {
            i++;
        }
        while (blocks[j] == -1)
        {
            j--;
        }
        swap(blocks[i], blocks[j]);
    }
    long long ans = 0;
    for (long long i = 0; blocks[i] != -1; i++)
    {
        ans += (i * blocks[i]);
    }
    cout << "Checksum: " << ans;
}