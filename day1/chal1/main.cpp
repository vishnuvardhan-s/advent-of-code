#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[1000], b[1000];
    for (int i = 0; i < 1000; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a, a + 1000);
    sort(b, b + 1000);
    long ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        ans += abs(a[i] - b[i]);
    }
    cout << "Total distance: " << ans << endl;
}