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

const ll mod = 1e9 + 7;

ll binpow(ll a, ll b, const ll MOD = mod)
{
    a = a % MOD;
    if (a == 0)
        return 0;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res % MOD) * (a % MOD);
            res %= MOD;
        }
        a %= MOD;
        a = (a % MOD) * (a % MOD);
        a %= MOD;
        b >>= 1;
    }
    return res % MOD;
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
        ll a[n + 5][2];
        ll loc[n + 5][2];
        ll d[n];
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> a[j][i];
                loc[a[j][i]][i] = j;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        ll p[n + 1][2] = {0};
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            // var(a[i][0], a[i][1], p[a[i][0]][0]);
            if (p[a[i][0]][0])
                continue;
            if (a[i][0] == a[i][1])
                continue;
            // dbg(1);
            queue<pii> q;
            ll baap = a[i][0];
            q.push({a[i][0], 0});
            while (!q.empty())
            {
                pii node = q.front();
                // var(node.ff, node.ss, -1);
                q.pop();
                if (p[node.ff][node.ss])
                    continue;
                p[node.ff][node.ss] = baap;
                q.push({a[loc[node.ff][node.ss]][!node.ss], !node.ss});
                q.push({node.ff, !node.ss});
            }
            res++;
        }
        // for (ll i = 1; i <= n; i++)
        // {
        //     cout << p[i][0] << " ";
        // }
        // cout << nl;
        set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            if (!d[i] || a[i][0] == a[i][1])
                continue;
            s.insert(p[a[i][0]][0]);
        }
        res -= s.size();

        ll mod = 1e9 + 7;
        cout << binpow(2, res) << nl;
    }
    return 0;
}