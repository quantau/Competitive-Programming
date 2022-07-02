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

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll out[n][m], in[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> in[i][j];
            out[i][j] = in[i][j];
        }
    }
    for (ll j = m - 1; j >= 0; j--)
    {
        for (ll i = n - 1; i >= 0; i--)
        {
            if (i > 0)
            {
                ll mn = min(in[i][j], out[i - 1][j]);
                in[i][j] -= mn;
                out[i - 1][j] -= mn;
            }
            if (j > 0)
            {
                ll mn = min(in[i][j], out[i][j - 1]);
                in[i][j] -= mn;
                out[i][j - 1] -= mn;
            }
        }
    }
    out[n - 1][m - 1] = 0;
    in[0][0] = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (in[i][j] != 0 || out[i][j] != 0)
            {
                // var(i, j, in[i][j], out[i][j]);
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
