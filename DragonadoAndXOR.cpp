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

void brute(ll a[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k < n; k++)
            {
                for (ll l = 0; l < n; l++)
                {
                    if (i == j || i == k || i == l || j == k || j == l || k == l)
                    {
                        continue;
                    }
                    if (on_bit(a[i] ^ a[j]) == on_bit(a[k] ^ a[l]))
                    {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

void solve(ll a[], ll n)
{
    for (ll i = 1; i <= 31; i++)
    {
        for (ll j = 33; j <= 63; j++)
        {
            if (on_bit(a[0] ^ a[i]) == on_bit(a[32] ^ a[j]))
            {
                cout << i + 1 << " " << 1 << " " << j + 1 << " " << 33 << endl;
                return;
            }
        }
    }
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
        if (n < 64)
        {
            brute(a, n);
        }
        else
        {
            solve(a, n);
        }
    }
    return 0;
}