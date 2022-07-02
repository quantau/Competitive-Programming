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

ll m[200001][31];
ll a[200001];
ll n;

ll query(ll a, ll b)
{
    ll i = msb(b - a + 1);
    return __gcd(m[a][i], m[b - (1 << i) + 1][i]);
}

int main()
{
    FASTIO
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i][0] = a[i];
    }
    for (ll j = 1; j <= 30; j++)
    {
        for (ll i = 0; i + (1 << j) - 1 < n; i++)
        {
            m[i][j] = __gcd(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }
    ll prev = -1, i = 0, ans = 0;
    for (ll j = 0; j < n; j++)
    {
        while (i < j && query(i, j) < (j - i + 1))
            i++;
        if (query(i, j) == (j - i + 1))
        {
            if (i > prev)
            {
                ans++, prev = j;
            }
        }
        cout << ans << " ";
    }
    cout << nl;
    return 0;
}