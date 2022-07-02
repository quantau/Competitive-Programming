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

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        pii x = {-1, -1}, b = {-1, -1}, c = {-1, -1}, d = {-1, -1};
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                char ch;
                cin >> ch;
                a[i][j] = (ch == 'B' ? 1 : 0);
                if (a[i][j])
                {
                    if (x.ff == -1 || i + j > x.ff + x.ss)
                        x = {i, j};
                    if (b.ff == -1 || i + j < b.ff + b.ss)
                        b = {i, j};
                    if (c.ff == -1 || i - j > c.ff - c.ss)
                        c = {i, j};
                    if (d.ff == -1 || i - j < d.ff - d.ss)
                        d = {i, j};
                }
            }
        }
        vector<pii> v;
        v.pb(x), v.pb(d), v.pb(b), v.pb(c);
        ll res = n + m + 5;
        pii p;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                ll dis = 0;
                for (auto x : v)
                {
                    dis = max(dis, abs(x.ff - i) + abs(x.ss - j));
                }
                if (res > dis)
                {
                    res = dis;
                    p = {i, j};
                }
            }
        }
        cout << p.ff + 1 << " " << p.ss + 1 << nl;
    }
    return 0;
}