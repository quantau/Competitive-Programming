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

ll rxor(ll a, ll b, ll k)
{
    ll res = 0, num = 1;
    while (a || b)
    {
        res += ((k - a % k + b % k) % k) * num;
        num *= k;
        a /= k, b /= k;
    }
    return res;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, r;
        cin >> n >> k;
        cout << 0 << endl;
        cin >> r;
        if (r == 1)
            continue;
        for (ll i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << rxor(i - 1, i, k) << endl;
            }
            else
            {
                cout << rxor(i, i - 1, k) << endl;
            }
            cin >> r;
            if (r == 1)
                break;
        }
    }
    return 0;
}