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
    vector<ll> v(2 * n);
    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        if (v[2 * i] != v[2 * i + 1])
        {
            cout << "NO\n";
            return;
        }
        a[i] = v[2 * i];
    }
    for (ll i = 1; i < n; i++)
    {
        if (v[2 * i] == v[2 * i - 2])
        {
            cout << "NO\n";
            return;
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << nl;
    ll sum = 0;
    ll prev = 1e12;
    for (ll i = n - 1; i >= 0; i--)
    {
        if ((a[i] - 2 * sum) <= 0 || (a[i] - 2 * sum) % (2 * i + 2))
        {
            cout << "NO\n";
            return;
        }
        ll curr = (a[i] - 2 * sum) / (2 * i + 2);
        if (curr >= prev)
        {
            cout << "NO\n";
            return;
        }
        prev = curr;
        sum += curr;
    }
    cout << "YES\n";
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