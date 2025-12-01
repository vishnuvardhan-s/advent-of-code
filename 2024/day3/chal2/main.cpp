#include <iostream>
#include <regex>
using namespace std;

long multiply(string &word)
{
    regex r("[0-9]+");
    auto numbers_begin = sregex_iterator(word.begin(), word.end(), r);
    auto numbers_end = sregex_iterator();
    long mul = 1;
    for (sregex_iterator i = numbers_begin; i != numbers_end; ++i)
    {
        smatch match = *i;
        string word = match.str();
        int num = stoi(word);
        mul *= num;
    }
    return mul;
}

int main()
{
    int times = 332;
    long ans = 0;
    bool ok = true;
    while (times--)
    {
        string s;
        getline(cin, s);
        regex r("(?:mul\\(([0-9]+),([0-9]+)\\))|(do\\(\\)|don't\\(\\))");
        auto words_begin = sregex_iterator(s.begin(), s.end(), r);
        auto words_end = sregex_iterator();

        for (sregex_iterator i = words_begin; i != words_end; ++i)
        {
            smatch match = *i;
            string word = match.str();
            if (ok and word[0] == 'm')
            {
                ans += multiply(word);
            }
            else
            {
                if (word == "do()")
                {
                    ok = true;
                }
                else
                {
                    ok = false;
                }
            }
        }
    }
    cout << "Multiplications result: " << ans;
}