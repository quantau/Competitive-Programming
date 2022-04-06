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

const ll inf = 1e17;

ll calc(vector<ll> sch, ll d)
{
    ll mn = inf, mx = 0;
    ll n = sch.size();
    for (ll i = 1; i < n; i++)
    {
        mn = min(mn, sch[i] - sch[i - 1] - 1);
        mx = max(mx, (sch[i] - sch[i - 1] - 2) / 2);
    }
    return min(mn, max(mx, d - sch[n - 1] - 1));
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll mn = a[0] - 1, mn_ind = 0;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] - 1 < mn)
            {
                mn = a[i] - a[i - 1] - 1;
                mn_ind = i;
            }
        }
        vector<ll> sch;
        sch.pb(0);
        for (ll i = 0; i < n; i++)
        {
            if (i != mn_ind)
                sch.pb(a[i]);
        }
        ll ans = calc(sch, d);
        if (mn_ind >= 1)
        {
            sch[mn_ind] = a[mn_ind];
        }
        ans = max(ans, calc(sch, d));
        cout << ans << nl;
    }
    return 0;
}