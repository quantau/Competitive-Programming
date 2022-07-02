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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll l = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (i == a[i])
                l++;
            else
            {
                break;
            }
        }
        ll r = l;
        for (ll i = l; i <= n; i++)
        {
            if (a[i] == l)
            {
                r = i;
                break;
            }
        }
        // var(l, r, -1);
        for (ll i = l; i <= (l + r) / 2; i++)
        {
            swap(a[i], a[r - (i - l)]);
            // var(i, r - (i - l), -1);
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << nl;
    }
    return 0;
}