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

ll mx[100001][31];
ll mn[100001][31];
ll a[100001], n;

ll getMin(ll a, ll b)
{
    ll i = msb(b - a + 1);
    return min(mn[a][i], mn[b - (1 << i) + 1][i]);
}

ll getMax(ll a, ll b)
{
    if (b < 0 || a >= n)
        return 0;
    ll i = msb(b - a + 1);
    return max(mx[a][i], mx[b - (1 << i) + 1][i]);
}

int main()
{
    FASTIO
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mx[i][0] = a[i];
        mn[i][0] = a[i];
    }
    for (ll j = 1; j <= 30; j++)
    {
        for (ll i = 0; i + (1 << j) - 1 < n; i++)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        // l--, r--;
        ll first = getMin(l, r);
        double ans = (max({2 * getMax(0, l - 1), 2 * getMax(r + 1, n - 1), (getMax(l, r) - first)}) + 0.0) / (2 + 0.0) + first;
        cout << ans << nl;
    }
    return 0;
}