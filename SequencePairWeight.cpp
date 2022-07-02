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
        ll a[n];
        map<ll, vector<ll>[2]> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]][0].pb(i + 1);
            mp[a[i]][1].pb(n - i);
        }
        // for (auto x : mp)
        // {
        //     for (auto z : (x.ss)[0])
        //     {
        //         cout << z << " ";
        //     }
        //     cout << nl;
        //     for (auto z : (x.ss)[1])
        //     {
        //         cout << z << " ";
        //     }
        //     cout << nl;
        // }
        ll res = 0;
        for (auto &x : mp)
        {
            ll j = 1;
            ll m = (x.ss)[j].size();
            for (ll i = 1; i < m; i++)
            {
                (x.ss)[j][i] += (x.ss)[j][i - 1];
            }
        }
        // for (auto x : mp)
        // {
        //     for (auto z : (x.ss)[0])
        //     {
        //         cout << z << " ";
        //     }
        //     cout << nl;
        //     for (auto z : (x.ss)[1])
        //     {
        //         cout << z << " ";
        //     }
        //     cout << nl;
        // }
        for (auto x : mp)
        {
            ll m = (x.ss)[0].size();
            for (ll i = 0; i < m; i++)
            {
                ll val = (x.ss)[1].back() - (x.ss)[1][i];
                res += val *(x.ss)[0][i];
                // var((x.ss)[1].back(),(x.ss)[1][i],(x.ss)[0][i]);
            }
        }
        cout << res << nl;
    }
    return 0;
}