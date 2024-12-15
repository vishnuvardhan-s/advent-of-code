#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<long long> &blocks)
{
    for (int i = 0; i < blocks.size(); i++)
    {
        if (blocks[i] == -1)
        {
            cout << ".";
        }
        else
        {
            cout << blocks[i];
        }
    }
    cout << endl;
}

int find(vector<long long> &blocks, int req)
{
    int run = 0;
    for (int i = 0; i < blocks.size(); i++)
    {
        if (blocks[i] == -1)
        {
            run++;
            if (run == req)
            {
                return i - req + 1;
            }
        }
        else
        {
            run = 0;
        }
    }
    return -1;
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
    while (--files)
    {
        int j = blocks.size() - 1;
        while (blocks[j] != files)
        {
            j--;
        }
        int req = 0;
        while (blocks[j] == files)
        {
            req++;
            j--;
        }
        int s = find(blocks, req);
        if (s != -1 and s <= j)
        {
            for (int i = s; i < s + req; i++)
            {
                swap(blocks[i], blocks[++j]);
            }
        }
    }
    long long ans = 0;
    for (long long i = 0; i < blocks.size(); i++)
    {
        if (blocks[i] != -1)
        {
            ans += (i * blocks[i]);
        }
    }
    cout << "Checksum: " << ans;
}