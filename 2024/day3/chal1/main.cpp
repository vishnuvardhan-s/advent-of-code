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
    int times = 6;
    long ans = 0;
    while (times--)
    {
        string s;
        getline(cin, s);
        regex r("mul\\([0-9]+,[0-9]+\\)");
        auto words_begin = sregex_iterator(s.begin(), s.end(), r);
        auto words_end = sregex_iterator();

        for (sregex_iterator i = words_begin; i != words_end; ++i)
        {
            smatch match = *i;
            string word = match.str();
            ans += multiply(word);
        }
    }
    cout << "Multiplications result: " << ans;
}