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

    ll n, q;
    cin >> n >> q;
    ll sum = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        mp[i + 1] = a;
        sum += a;
    }
    ll prev_val = -1;
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 2)
        {
            mp.clear();
            ll x;
            cin >> x;
            prev_val = x;
            sum = x * n;
        }
        else
        {
            ll i, x;
            cin >> i >> x;
            // var(sum, mp[i], -1);
            if (mp.count(i))
            {
                sum = sum - mp[i] + x;
            }
            else
            {
                sum = sum - prev_val + x;
            }
            mp[i] = x;
        }
        cout << sum << nl;
    }
    return 0;
}