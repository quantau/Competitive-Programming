#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w, q) cout << x << " " << y << " " << z << " " << w << " " << q << endl;
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
    if (n >= 64)
    {
        cout << 1 << endl;
    }
    else
    {
        for (ll i = 1; i < n; i++)
        {
            a[i] ^= a[i - 1];
        }
        ll ans = n + 1;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i; j < n; j++)
            {
                ll l;
                if (i == 0)
                {
                    l = a[j];
                }
                else
                {
                    l = a[j] ^ a[i - 1];
                }
                for (ll k = j + 1; k < n; k++)
                {
                    ll r = a[k] ^ a[j];
                    // var(l, r, i, j, k);
                    if (r < l)
                    {
                        ans = min(ans, k - i - 1);
                    }
                }
            }
        }
        cout << (ans >= n ? -1 : ans) << endl;
    }
}

int main()
{
    FASTIO
    solve();
    return 0;
}