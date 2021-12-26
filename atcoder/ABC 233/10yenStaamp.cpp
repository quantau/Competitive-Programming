#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll unsigned long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

ll n, x;

ll solve(ll i, ll val, vector<ll> adj[])
{
    ll res = 0;
    if (i == n)
    {
        return val == x;
    }
    for (auto z : adj[i])
    {
        ll val_org = val;
        val *= z;
        if (val < 0 || val > x)
        {
            val = val_org;
            continue;
        }
        res += solve(i + 1, val, adj);
        val = val_org;
    }
    return res;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> x;
    vector<ll> adj[n];
    for (ll i = 0; i < n; i++)
    {
        ll l;
        cin >> l;
        for (ll j = 0; j < l; j++)
        {
            ll y;
            cin >> y;
            adj[i].pb(y);
        }
    }
    cout << solve(0, 1, adj) << nl;
    return 0;
}