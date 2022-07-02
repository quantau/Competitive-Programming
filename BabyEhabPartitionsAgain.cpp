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

bool dp[200001];

int main()
{
    FASTIO

    ll n;
    cin >> n;
    ll a[n];
    ll g = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        g = __gcd(g, a[i]);
        sum += a[i];
    }
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = sum; j >= 1; j--)
        {
            if (j - a[i - 1] >= 0)
            {
                dp[j] = max(dp[j], dp[j - a[i - 1]]);
            }
        }
    }
    if (sum % 2 || !dp[sum / 2])
    {
        cout << 0 << nl;
        return 0;
    }
    ll j;
    for (ll i = 0; i < n; i++)
    {
        a[i] /= g;
        if (a[i] % 2)
        {
            j = i;
            break;
        }
    }
    cout << 1 << "\n"
         << j + 1 << nl;
    return 0;
}