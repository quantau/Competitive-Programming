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

const ll inf = 1e17;

ll solve(ll a, ll b)
{
    if (b == 1)
        return a - 1;
    if (b == 0)
        return inf;
    return solve(b, a % b) + a / b;
}

int main()
{
    FASTIO

    ll n;
    cin >> n;
    ll res = n;
    for (ll i = 1; i <= n; i++)
    {
        res = min(res, solve(n, i));
    }
    cout << res << nl;
    return 0;
}