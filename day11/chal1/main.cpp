#include <iostream>
#include <sstream>
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

int main()
{
    vector<long long> nums = {64554, 35, 906, 6, 6960985, 5755, 975820, 0};
    int times = 25;
    while (times--)
    {
        vector<long long> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                temp.push_back(1);
            }
            else if (to_string(nums[i]).length() % 2 == 0)
            {
                string num = to_string(nums[i]);
                string left_side = num.substr(0, num.length() / 2);
                string right_side = num.substr(num.length() / 2);
                temp.push_back(stoll(left_side));
                temp.push_back(stoll(right_side));
            }
            else
            {
                temp.push_back(nums[i] * 2024);
            }
        }
        nums = temp;
    }
    cout << "After 25 blinks: " << nums.size();
}