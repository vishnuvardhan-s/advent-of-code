#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int a[1000], b[1000];
    unordered_map<int, int> mp;
    for (int i = 0; i < 1000; i++)
    {
        cin >> a[i] >> b[i];
        mp[b[i]]++;
    }
    long ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        ans += (a[i] * mp[a[i]]);
    }
    cout << "Similarity Score: " << ans << endl;
}