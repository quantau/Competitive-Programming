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
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        vector<pii> v;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
                v.pb({a[i][j], j});
            }
        }
        sort(all(v));
        
        ll x = v.size();
        set<ll> s;
        vector<ll> freq(m + 1, 0);
        ll j = 0;
        for (ll i = 0; i < x; i++)
        {
            while (s.size() > m)
            {
                freq[v[j].ss]--;
                if (!freq[v[j].ss])
                {
                    s.erase(v[j].ss);
                    j++;
                }
            }
        }
    }
    return 0;
}