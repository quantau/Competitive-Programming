#include <bits/stdc++.h>
#define sz(x) x.size()
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second

using namespace std;

vector<pii> adj[4009000];
bool vis[4009000];
int inf = 1e9 + 7;
vector<int> mn(4009000, inf);

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int A, B, n, m;
    cin >> A >> B >> n >> m;
    vector<int> ver(n + 2), hor(m + 2);
    ver[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> ver[i];
    }
    ver[n + 1] = A;
    hor[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> hor[i];
    }
    hor[m + 1] = B;
    sort(aint(ver));
    sort(aint(hor));
    for (int i = 1; i <= m + 1; i++)
    {
        int w = hor[i] - hor[i - 1];
        for (int j = (i - 1) * (n + 1); j < i * (n + 1) - 1; j++)
        {
            int u = j, v = j + 1;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        int w = ver[i] - ver[i - 1];
        for (int j = 0; j < m; j++)
        {
            int u = (i - 1) + j * (n + 1), v = (i - 1) + (j + 1) * (n + 1);
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
    }
    // for (int i = 0; i < (n + 1) * (m + 1); i++)
    // {
    //     for (auto x : adj[i])
    //     {
    //         printf("||%d--%d->%d||  ", i, x.ff, x.ss);
    //     }
    //     dbg(1);
    //     // cout << nl;
    //     // cout << nl;
    // }
    set<pii> q;
    q.insert({0, 0});
    mn[0] = 0;
    ll ans = 0;
    while (!q.empty())
    {
        int u = (*q.begin()).ss;
        ans += (*q.begin()).ff;
        q.erase(q.begin());
        vis[u] = true;
        for (auto x : adj[u])
        {
            if (!vis[x.ff] && mn[x.ff] > x.ss)
            {
                q.erase({mn[x.ff], x.ff});
                mn[x.ff] = x.ss;
                q.insert({x.ss, x.ff});
            }
        }
    }
    cout << ans << nl;
    return 0;
}