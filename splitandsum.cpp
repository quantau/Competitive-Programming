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

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < 30; i++)
    {
        ll num = (1 << i);
        vector<ll> res;
        for (ll j = 0; j < n; j++)
        {
            if (num & a[j])
            {
                res.pb(j + 1);
            }
        }
        if (res.size() > 1)
        {
            cout << "YES\n";
            cout << res.size() << nl;
            cout << 1 << " " << res[0] << nl;
            for (ll l = 1; l < res.size() - 1; l++)
            {
                cout << res[l - 1] + 1 << " " << res[l] << nl;
            }
            cout << res[res.size() - 2] + 1 << " " << n << nl;
            return;
        }
    }
    cout << "NO\n";
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