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

vector<ll> adj[100005];
bool state[100005];

int main()
{
    FASTIO
    ll n, m, q;
    cin >> n >> m >> q;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // cout << endl;
    vector<ll> v;
    while (q--)
    {
        ll query;
        cin >> query;
        if (query == 1)
        {
            ll x;
            cin >> x;
            if (!state[x])
            {
                // dbg(-1);
                state[x] = true;
                v.pb(x);
                // var(-1, v.size(), -1);
            }
        }
        else if (query == 3)
        {
            ll x;
            cin >> x;
            cout << (state[x] ? "YES\n" : "NO\n");
        }
        else
        {
            ll time;
            cin >> time;
            queue<pii> q;
            // dbg(v.size());
            for (auto x : v)
            {
                q.push({x, time});
                // var(x, time, -1);
            }
            v.clear();
            while (!q.empty())
            {
                ll u = q.front().ff;
                ll t = q.front().ss;
                q.pop();
                if (t == 0)
                {
                    v.pb(u);
                    continue;
                }
                for (auto x : adj[u])
                {
                    if (state[x])
                        continue;
                    state[x] = true;
                    q.push({x, t - 1});
                }
            }
        }
    }
    return 0;
}