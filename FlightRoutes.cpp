#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

ll inf = 1e17;
vector<pii> adj[200001];
ll d[100001][20];

bool check(ll u, ll k, ll dis)
{
    for (ll i = 0; i < k; i++)
    {
        if (d[u][i] == dis)
            return true;
    }
    return false;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            d[i][j] = inf;
        }
    }
    d[1][0] = 0;
    // for (ll i = 0; i < k; i++)
    // {
    //     d[1][i] = 0;
    // }
    priority_queue<pii> q;
    q.push({0, 1});
    while (!q.empty())
    {
        ll u = q.top().ss;
        ll dis = -q.top().ff;
        q.pop();
        if (!check(u, k, dis))
        {
            continue;
        }
        for (auto x : adj[u])
        {
            for (ll i = 0; i < k; i++)
            {
                if (d[x.ff][i] > dis + x.ss)
                {
                    for (ll j = k - 2; j >= i; j--)
                    {
                        d[x.ff][j + 1] = d[x.ff][j];
                    }
                    d[x.ff][i] = dis + x.ss;
                    q.push({-d[x.ff][i], x.ff});
                    break;
                }
            }
        }
    }
    for (ll i = 0; i < k; i++)
    {
        cout << d[n][i] << " ";
    }
    cout << nl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 0; j < k; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    return 0;
}