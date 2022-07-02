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

ll n, m;
vector<ll> adj[700001];
bool vis[700001];
ll col[700001];
string str = "imposter";
ll c[2] = {0, 0};
bool poss = true;

void dfs(ll node, bool b)
{
    vis[node] = true;
    col[node] = b;
    if (node <= n)
    {
        c[b]++;
    }
    for (auto x : adj[node])
    {
        if (vis[x])
        {
            if (col[x] == b)
            {
                poss = false;
                return;
            }
            continue;
        }
        dfs(x, !b);
    }
}

void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= m + n; i++)
    {
        adj[i].clear();
        vis[i] = 0;
        col[i] = 0;
    }
    ll j = n + 1;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        string s;
        cin >> x >> y >> s;
        if (s == str)
        {
            adj[x].pb(y);
            adj[y].pb(x);
        }
        else
        {
            adj[x].pb(j);
            adj[j].pb(x);
            adj[y].pb(j);
            adj[j].pb(y);
            j++;
        }
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            c[0] = 0, c[1] = 0;
            poss = true;
            dfs(i, 0);
            if (!poss)
            {
                cout << -1 << nl;
                return;
            }
            res += max(c[0], c[1]);
        }
    }
    cout << res << nl;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}