#include <iostream>
#include <sstream>
#include <map>
using namespace std;

vector<long long> split(string sen, char delimiter)
{
    stringstream ss(sen);
    string word;
    vector<long long> words;
    while (getline(ss, word, delimiter))
    {
        int num = stoll(word);
        words.push_back(num);
    }
    return words;
}

map<pair<long long, long long>, long long> cache;

long long solve(long long num, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (cache.find({num, n}) == cache.end())
    {
        long long res = 0;
        if (num == 0)
        {
            res = solve(1, n - 1);
        }
        else if (to_string(num).length() % 2 == 0)
        {
            string s = to_string(num);
            string left_side = s.substr(0, s.length() / 2);
            string right_side = s.substr(s.length() / 2);
            res += solve(stoll(left_side), n - 1);
            res += solve(stoll(right_side), n - 1);
        }
        else
        {
            res = solve(num * 2024, n - 1);
        }
        cache[{num, n}] = res;
    }
    return cache[{num, n}];
}

int main()
{
    string s;
    cin >> s;
    vector<long long> nums = {64554, 35, 906, 6, 6960985, 5755, 975820, 0};
    int times = 75;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += solve(nums[i], 75);
    }
    cout << "After 75 blinks: " << ans;
}