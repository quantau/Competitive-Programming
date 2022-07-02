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

    ll n;
    cin >> n;
    ll time[n + 2];
    for (ll i = 1; i <= n; i++)
    {
        cin >> time[i];
    }
    time[0] = 0, time[n + 1] = 91;
    ll res = 0;
    for (ll i = 1; i <= n + 1; i++)
    {
        if (time[i] - time[i - 1] - 1 >= 15)
        {
            res += 15;
            break;
        }
        else
        {
            res += time[i] - time[i - 1];
        }
    }
    cout << res - (res > 90 ? 1 : 0) << nl;
    return 0;
}