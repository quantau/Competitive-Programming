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

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll Sx = 0, Sy = 0, Sxy = 0;
    for (ll i = 0; i < n; i++)
    {
        (Sx += (a[i] % mod) * (a[i] % mod) % mod) %= mod;
        (Sy += (b[i] % mod) * (b[i] % mod) % mod) %= mod;
        (Sxy += (a[i] % mod) * (b[i] % mod) % mod) %= mod;
    }
    //var(Sx, Sy, Sxy);
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x = ((a[i] % mod) * (a[i] % mod) % mod);
        ll y = ((b[i] % mod) * (b[i] % mod) % mod);
        ll xy = ((a[i] % mod) * (b[i] % mod) % mod);
       // var(x, y, xy);
        (res += (x * (mod + Sy - y) % mod) % mod + (y * (mod + Sx - x) % mod) % mod - (2 * xy * (mod + Sxy - xy) % mod) % mod) %= mod;
        (Sx -= x - mod) %= mod;
        (Sy -= y - mod) %= mod;
        (Sxy -= xy - mod) %= mod;
        //dbg(res);
    }
    cout << res << nl;
    return 0;
}