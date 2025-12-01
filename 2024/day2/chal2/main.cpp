#include <iostream>
using namespace std;

int INCREASING = 1;
int DECREASING = -1;

vector<vector<int>> get_input()
{
    int num;
    vector<vector<int>> data;
    while (cin >> num)
    {
        vector<int> row;
        row.push_back(num);
        while (cin.peek() == ' ' || cin.peek() == '\t')
        {
            cin >> num;
            row.push_back(num);
        }
        data.push_back(row);
        cin.ignore();
    }
    return data;
}

bool ok(vector<int> &a, int flow)
{
    int prev = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        int diff = flow == INCREASING ? a[i] - prev : prev - a[i];
        if (diff < 1 or diff > 3)
        {
            return false;
        }
        prev = a[i];
    }
    return true;
}
int main()
{
    vector<vector<int>> data = get_input();
    int ans = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (ok(data[i], INCREASING))
        {
            ans++;
        }
        else if (ok(data[i], DECREASING))
        {
            ans++;
        }
        else
        {
            for (int j = 0; j < data[i].size(); j++)
            {
                vector<int> t = data[i];
                t.erase(t.begin() + j);
                if (ok(t, INCREASING))
                {
                    ans++;
                    break;
                }
                else if (ok(t, DECREASING))
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << "Safe Reports: " << ans;
}