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

ll p[200001], d[200001], vis[200001];
ll cycle;

void dfs1(ll u)
{
    vis[u] = true;
    if (d[p[u]])
    {
        d[u] = d[p[u]] + 1;
        return;
    }
    if (vis[p[u]])
    {
        cycle = p[u];
        d[u] = 1;
    }
    else
    {
        dfs1(p[u]);
        d[u] = d[p[u]] + 1;
    }
}

void dfs2(ll u, ll par)
{
    d[u] = d[par];
    if (par == p[u])
    {
        return;
    }
    else
    {
        dfs2(p[u], par);
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            dfs1(i);
            dfs2(cycle, cycle);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << nl;
    return 0;
}