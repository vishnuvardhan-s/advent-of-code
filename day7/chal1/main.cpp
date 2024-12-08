#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;

vector<string> split(string sen, char delimiter)
{
    stringstream ss(sen);
    string word;
    vector<string> words;
    while (getline(ss, word, delimiter))
    {
        word.erase(word.find_last_not_of(' ') + 1);
        word.erase(0, word.find_first_not_of(' '));
        words.push_back(word);
    }
    return words;
}

void ok(vector<long long> &nums, long long key, vector<char> &ops, int i, long long &ans)
{
    if (i == ops.size())
    {
        long long temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (ops[i - 1] == '*')
            {
                temp += nums[i];
            }
            else
            {
                temp *= nums[i];
            }
        }
        if (temp == key)
        {
            ans++;
        }
        return;
    }
    ops[i] = '+';
    ok(nums, key, ops, i + 1, ans);
    ops[i] = '*';
    ok(nums, key, ops, i + 1, ans);
}

int main()
{
    int times = 850;
    long long fans = 0;
    while (times--)
    {
        string s;
        getline(cin, s);
        long long ans = 0;
        vector<string> res = split(s, ':');
        long key = stol(res[0]);
        vector<string> values = split(res[1], ' ');
        vector<long long> nums;
        for (string &value : values)
        {
            nums.push_back(stoi(value));
        }
        vector<char> ops(nums.size() - 1);
        ok(nums, key, ops, 0, ans);
        if (ans > 0)
        {
            fans += key;
        }
    }
    cout << "Total calibration result: " << fans;
}