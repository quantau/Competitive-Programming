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

using namespace std;

ll binpow(ll a, ll b, const ll MOD)
{
    a = a % MOD;
    if (a == 0)
        return 0;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res % MOD) * (a % MOD);
            res %= MOD;
        }
        a %= MOD;
        a = (a % MOD) * (a % MOD);
        a %= MOD;
        b >>= 1;
    }
    return res % MOD;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll mx = 1;
        ll c = 1;
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            while (x % 2 == 0)
            {
                x /= 2;
                c *= 2;
            }
            res += x;
            mx = max(x, mx);
        }
        cout << res - mx + mx * c << nl;
    }
    return 0;
}