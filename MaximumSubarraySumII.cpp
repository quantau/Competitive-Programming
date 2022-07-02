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

    ll n, l, r;
    cin >> n >> l >> r;
    ll a[n + 1];
    a[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    multiset<ll> s;
    ll mx = -1e16;
    for (ll i = l; i <= n; i++)
    {
        s.insert(a[i - l]);
        auto it = s.begin();
        mx = max(mx, a[i] - *it);
        // var(a[i], *it, -1);
        if (i >= r)
        {
            s.erase(s.find(a[i - r]));
        }
    }
    cout << mx << nl;
    return 0;
}