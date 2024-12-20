#include <iostream>
#include <sstream>
#include <numeric>
using namespace std;

vector<string> split(string sen, char delimiter)
{
    stringstream ss(sen);
    string word;
    vector<string> words;
    while (getline(ss, word, delimiter))
    {
        words.push_back(word);
    }
    return words;
}

int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int findPositiveSolutions(uint x, uint y, int X, int x2, int y2, int Y)
{
    int g = __gcd(x, y);

    if (X % g != 0)
    {
        return 0;
    }

    vector<pair<int, int>> solutions;
    int a0, b0;
    extended_gcd(x, y, a0, b0);
    a0 *= (X / g);
    b0 *= (X / g);

    int k_lower = (int)ceil((double)(-a0 * g) / y);
    int k_upper = (int)floor((double)(b0 * g) / x);

    for (int k = k_lower; k <= k_upper; ++k)
    {
        int a = a0 + (y / g) * k;
        int b = b0 - (x / g) * k;
        if (a > 0 && b > 0 and (a * x2 + b * y2 == Y))
        {
            solutions.push_back({a, b});
        }
    }
    if (solutions.size() == 0)
    {
        return 0;
    }
    long ans = LONG_MAX;
    for (auto solution : solutions)
    {
        ans = min(ans, (long)(solution.first * 3 + solution.second));
    }
    return ans;
}

int main()
{
    int times = 320;
    long ans = 0;
    for (int i = 1; i <= times; i++)
    {
        string l1, l2, l3, l4;
        getline(cin, l1);
        getline(cin, l2);
        getline(cin, l3);
        getline(cin, l4);
        vector<string> b1 = split(l1, ',');
        vector<string> b2 = split(l2, ',');
        vector<string> t = split(l3, ',');
        uint x1 = stoi(split(b1[0], '+')[1]);
        uint y1 = stoi(split(b1[1], '+')[1]);
        uint x2 = stoi(split(b2[0], '+')[1]);
        uint y2 = stoi(split(b2[1], '+')[1]);
        int X = stoi(split(t[0], '=')[1]);
        int Y = stoi(split(t[1], '=')[1]);
        ans += findPositiveSolutions(x1, x2, X, y1, y2, Y);
    }
    cout << "Fewest tokens: " << ans;
}