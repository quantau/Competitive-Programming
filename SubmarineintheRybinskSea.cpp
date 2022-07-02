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

ll mod = 998244353;

ll dig(ll n)
{
    ll res = 0;
    while (n > 0)
    {
        res++;
        n /= 10;
    }
    return res;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    ll a[n];
    vector<ll> v(12, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        v[dig(a[i])]++;
    }
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= 10; j++)
        {
            if (!v[j])
                continue;
            ll c = a[i];
            ll d = j, r = 0, val = 0;
            ll base = 1;
            while (c && d)
            {
                val += ((c % 10) * base % mod) % mod;
                val %= mod;
                c /= 10;
                base *= 100;
                base %= mod;
                d--;
            }
            val *= 11;
            val %= mod;
            r += val;
            r %= mod;
            val = 0;
            while (c)
            {
                val += ((c % 10) * base % mod) % mod;
                val %= mod;
                c /= 10;
                base *= 10;
                base %= mod;
            }
            // var(r / 11, val, i);
            val *= 2;
            val %= mod;
            r += val;
            r %= mod;
            r *= v[j] % mod;
            r %= mod;
            res += r;
            res %= mod;
        }
    }
    cout << res % mod << nl;
    return 0;
}