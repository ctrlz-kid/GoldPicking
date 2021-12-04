#include <iostream>
#include <algorithm>
using namespace std;

struct Gold
{
    double m, v;
    double p;
}g[110];

bool cmp(Gold x, Gold y)
{
    return x.p > y.p;
}

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i].m >> g[i].v;
        g[i].p = g[i].v / g[i].m;
    }
    sort(g + 1, g + n + 1, cmp);
    
    double ans = 0;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += g[i].v;
        sum += g[i].m;
        if (sum > t)
        {
        	ans -= (sum - t) * g[i].p;
        	break;
        }
    }
    cout << ans << endl;
    return 0;
}