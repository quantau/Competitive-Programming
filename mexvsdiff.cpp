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
        ll n, k;
        cin >> n >> k;
        k = min(n, k);
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            mp[a]++;
        }
        ll mex = 0;
        ll moves = 0;
        for (ll i = 0; i < n; i++)
        {
            if (mp[i])
            {
                mex = i + 1;
            }
            else if (k)
            {
                k--, moves++;
                mex = i + 1;
            }
            else
            {
                break;
            }
        }
        vector<ll> v;
        for (auto x : mp)
        {
            if (x.ff >= mex)
            {
                v.pb(x.ss);
            }
        }
        sort(all(v));
        ll res = v.size();
        for (auto x : v)
        {
            if (moves >= x)
            {
                res--;
                moves -= x;
            }
        }
        cout << res << nl;
    }
    return 0;
}