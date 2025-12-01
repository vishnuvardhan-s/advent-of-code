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

long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long findPositiveSolutions(unsigned long long x, unsigned long long y, long long X, long long x2, long long y2, long long Y)
{
    long long g = __gcd(x, y);

    if (X % g != 0)
    {
        return 0;
    }

    vector<pair<long long, long long>> solutions;
    long long a0, b0;
    extended_gcd(x, y, a0, b0);
    a0 *= (X / g);
    b0 *= (X / g);

    long long k_lower = (long long)ceil((long double)(-a0 * g) / y);
    long long k_upper = (long long)floor((long double)(b0 * g) / x);

    for (long long k = k_lower; k <= k_upper; ++k)
    {
        long long a = a0 + (y / g) * k;
        long long b = b0 - (x / g) * k;
        if (a > 0 && b > 0 and (a * x2 + b * y2 == Y))
        {
            solutions.push_back({a, b});
        }
    }
    if (solutions.size() == 0)
    {
        return 0;
    }
    long long ans = LONG_MAX;
    for (auto solution : solutions)
    {
        ans = min(ans, (long long)(solution.first * 3 + solution.second));
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
        long long x1 = stoll(split(b1[0], '+')[1]);
        long long y1 = stoll(split(b1[1], '+')[1]);
        long long x2 = stoll(split(b2[0], '+')[1]);
        long long y2 = stoll(split(b2[1], '+')[1]);
        long long X = stoll(split(t[0], '=')[1]);
        long long Y = stoll(split(t[1], '=')[1]);
        ans += findPositiveSolutions(x1, x2, X, y1, y2, Y);
    }
    cout << "Fewest tokens: " << ans;
}