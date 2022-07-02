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
vector<ll> adj[300001];
ll a[300001]; // 0 means sum and 1 means min
vector<ll> r(300001);
ll leaf = 0;

void dfs(ll node, ll p)
{
    if (adj[node].size() == 1 && adj[node][0] == p)
    {
        leaf++;
        r[node] = 1;
        return;
    }
    r[node] = (a[node] ? INT_MAX : 0);
    for (auto x : adj[node])
    {
        if (x == p)
            continue;
        dfs(x, node);
        if (a[node])
        {
            r[node] = min(r[node], r[x]);
        }
        else
        {
            r[node] += r[x];
        }
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
        cin >> a[i];
    for (ll i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        adj[x].pb(i + 2);
        adj[i + 2].pb(x);
    }
    dfs(1, 0);
    ll res = r[1];
    cout << leaf - res + 1 << nl;
    return 0;
}