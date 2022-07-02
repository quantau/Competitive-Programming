#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
// #define int long long
// const int INF=1e15;
// const int mod=1e9 + 7;
const int N = 2e5 + 1;
vector<pair<int, int>> g[N];
// bool vis[N];
int ans[N];
void dfs(int u, int p, bool x)
{

    for (auto v : g[u])
    {
        if (v.first != p)
        {
            if (x)
            {
                ans[v.second] = 2;
                x = 0;
            }
            else
            {
                ans[v.second] = 5;
                x = 1;
            }
            dfs(v.first, u, x);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    bool f = 1;
    vector<int> deg(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(make_pair(v, i));
        g[v].push_back(make_pair(u, i));
        deg[u]++;
        deg[v]++;
        if (deg[u] > 2 || deg[v] > 2)
        {
            f = 0;
        }
    }
    if (!f)
    {
        cout << -1 << endl;
        return;
    }
    int st = 1;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            st = i;
            break;
        }
    }
    // cout<<st<<endl;
    dfs(st, st, 1);
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
        ans[i] = 0;
        g[i].clear();
        // vis[i]=0;
    }
    g[0].clear();
    g[n].clear();
    // vis[n]=0;
    cout << endl;
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}