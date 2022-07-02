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

ll m[200005][31];

int main()
{
    FASTIO
    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for (ll j = 1; j <= 30; j++)
    {
        for (ll i = 0; i + (1 << j) - 1 < n; i++)
        {
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        ll po = msb(b - a + 1);
        cout << min(m[a][po], m[b - (1 << po) + 1][po]) << nl;
    }
    return 0;
}