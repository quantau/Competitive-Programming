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

ll solve(ll h[], ll n, ll val)
{
    ll a = 0, b = 0;
    for (ll i = 0; i < n; i++)
    {
        b += (h[i] % 2 != val % 2);
        a += (val - h[i]) / 2;
    }
    if (b >= a)
    {
        return max(2 * a, 2 * b - 1);
    }
    ll res = max(2 * a, 2 * b - 1);
    for (ll i = 0; i < n; i++)
    {
        ll num = (val - h[i]) / 2;
        num = min((a - b + 1) / 3, num);
        a -= num;
        b += 2 * num;
        res = max(2 * a, 2 * b - 1);
    }
    return res;
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
        ll h[n];
        ll mx = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> h[i];
            mx = max(mx, h[i]);
        }
        sort(h, h + n);
        ll rs = min(solve(h, n, mx), solve(h, n, mx + 1));
        cout << rs << nl;
    }
    return 0;
}