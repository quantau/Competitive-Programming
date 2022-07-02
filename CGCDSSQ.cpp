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

ll m[100001][31];
ll a[100001];
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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll r = i, prevr = i;
        while (r < n)
        {
            ll g = query(i, r);
            ll lo = r, hi = n - 1;
            ll res = n;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                if (query(i, mid) != g)
                {
                    res = min(res, mid);
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            prevr = r;
            r = res;
            mp[g] += r - prevr;
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        cout << mp[x] << nl;
    }
    return 0;
}