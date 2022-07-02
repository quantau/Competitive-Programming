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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i] % 10]++;
    }
    for (ll i = 0; i < 10; i++)
    {
        if (!mp[i])
            continue;
        ll sum = i;
        mp[i]--;
        for (ll j = 0; j < 10; j++)
        {
            if (!mp[j])
                continue;
            sum += j;
            mp[j]--;
            sum %= 10;
            if (mp[(13 - sum) % 10])
            {
                cout << "YES\n";
                return;
            }
            mp[j]++;
            sum = (10 + sum - j) % 10;
        }
        mp[i]++;
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