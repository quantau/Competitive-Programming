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

void reduce(ll a[], ll n, vector<ll> &v)
{
    map<ll, ll> mp[2];
    for (ll i = 0; i < n; i++)
    {
        mp[0][a[i]]++;
        mp[1][a[i]] = i;
    }
    vector<pii> vec;
    for (auto x : mp[1])
    {
        vec.pb({x.ss, x.ff});
    }
    sort(all(vec));
    for (auto x : vec)
    {
        ll val = mp[0][x.ss];
        while (val--)
        {
            v.pb(x.ss);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    ll b[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[a[i]].pb(i);
    }
    // for (auto x : mp)
    // {
    //     cout << x.ff << " : ";
    //     for (auto z : x.ss)
    //     {
    //         cout << z << " ";
    //     }
    //     cout << nl;
    // }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> v;
    reduce(b, n, v);
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << nl;
    bool placed[n] = {0};
    ll j = n - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        ll loc = mp[v[i]].back();
        mp[v[i]].pop_back();
        while (placed[j])
            j--;
        var(i, j, loc);
        if (loc == j)
        {
            placed[j] = 1;
            j--;
        }
        else if (loc < j && !mp[v[i]].empty())
        {
            placed[loc] = 1;
        }
        else
        {
            cout << "NO\n";
            return;
        }
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