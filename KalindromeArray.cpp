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

bool solve(ll a[], ll n, ll x)
{
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == x)
            continue;
        v.pb(a[i]);
    }
    ll m = v.size();
    for (ll i = 0; i <= m / 2; i++)
    {
        if (v[i] != v[m - i - 1])
            return false;
    }
    return true;
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
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll val = -1;
        for (ll i = 0; i <= n / 2; i++)
        {
            if (a[i] == a[n - i - 1])
                continue;
            else
            {
                val = i;
                break;
            }
        }
        if (val == -1 || solve(a, n, a[val]) || solve(a, n, a[n - 1 - val]))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}