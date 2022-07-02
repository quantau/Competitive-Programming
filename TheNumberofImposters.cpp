#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

vector<pii> adj[200001];
bool vis[200001];
bool parity[200001]; //0-->crewmate 1-->imposter
bool poss = true;
ll csz = 0, imps = 0;
string str = "imposter"; //2--> crewmate 1-->imposter

void dfs(ll node, bool b)
{
    csz++;
    imps += b;
    vis[node] = true;
    parity[node] = b;
    for (auto x : adj[node])
    {
        if (vis[x.ff])
        {
            ll val;
            if (x.ss > 0)
            {
                if (!b)
                {
                    val = (x.ss == 1 ? 1 : 0);
                }
                else
                {
                    val = (x.ss == 2 ? 1 : 0);
                }
                if (val != parity[x.ff])
                {
                    // dbg(1);
                    poss = false;
                    return;
                }
            }
            else
            {
                if (!parity[x.ff])
                {
                    val = (x.ss == -1 ? 1 : 0);
                }
                else
                {
                    val = (x.ss == -2 ? 1 : 0);
                }
                if (val != b)
                {
                    // var(node, x.ff, val, b);
                    // dbg(parity[x.ff]);
                    poss = false;
                    return;
                }
            }
            continue;
        }
        if (!poss)
            return;
        ll val;
        if (x.ss > 0)
        {
            if (!b)
            {
                val = (x.ss == 1 ? 1 : 0);
            }
            else
            {
                val = (x.ss == 2 ? 1 : 0);
            }
            dfs(x.ff, val);
        }
        else
        {
            val = (x.ss == -1 ? 1 : 0);
            if (b == val)
            {
                dfs(x.ff, 0);
            }
            else
            {
                dfs(x.ff, 1);
            }
        }
    }
}

void solve()
{
    poss = true;
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = 0;
        parity[i] = 0;
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        string s;
        cin >> x >> y >> s;
        if (s == str)
        {
            adj[x].pb({y, 1});
            adj[y].pb({x, -1});
        }
        else
        {
            adj[x].pb({y, 2});
            adj[y].pb({x, -2});
        }
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            csz = 0, imps = 0;
            dfs(i, 0);
            if (!poss)
            {
                cout << -1 << nl;
                return;
            }
            res += max(imps, csz - imps);
            // var(imps, csz, res);
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