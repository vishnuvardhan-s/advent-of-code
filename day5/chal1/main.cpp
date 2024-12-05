#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;
vector<int> split(string sen, char delimiter)
{
    stringstream ss(sen);
    string word;
    vector<int> words;
    while (getline(ss, word, delimiter))
    {
        int num = stoi(word);
        words.push_back(num);
    }
    return words;
}

int main()
{
    long ans = 0;
    int rules = 1176;
    unordered_map<int, unordered_set<int>> mp;
    while (rules--)
    {
        string s;
        cin >> s;
        vector<int> arr = split(s, '|');
        mp[arr[0]].insert(arr[1]);
    }

    int updates = 201;
    while (updates--)
    {
        string s;
        cin >> s;
        vector<int> arr = split(s, ',');
        bool flag = true;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (mp[arr[i]].find(arr[j]) == mp[arr[i]].end())
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            ans += arr[arr.size() / 2];
        }
    }
    cout << "Adding up middle page numbers " << ans;
}