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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

vector<ll> adj[200005];
int col[200005];
int subtree[200005];

void dfs(ll u, ll p)
{
    subtree[u] = col[u];
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs(x, u);
        subtree[u] += subtree[x];
    }
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
        ll a[n + 1];
        for (ll i = 2; i <= n; i++)
        {
            cin >> a[i];
            adj[i].pb(a[i]);
            adj[a[i]].pb(i);
        }
        string s;
        cin >> s;
        for (ll i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'W')
            {
                col[i] = 1;
            }
            else
            {
                col[i] = -1;
            }
        }
        dfs(1, 0);
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (!subtree[i])
                res++;
        }
        cout << res << nl;
    }
    return 0;
}