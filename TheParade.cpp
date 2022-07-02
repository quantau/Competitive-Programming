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

bool ok(ll k, ll x, ll n, ll c[])
{
    ll cont = 0, rem = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll num = c[i];
        if (num >= x - rem)
        {
            num -= (x - rem);
            cont++;
        }
        cont += num / x;
        rem = num % x;
    }
    if (cont >= k)
        return true;
    return false;
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
        ll n, k;
        cin >> n >> k;
        ll c[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        ll lo = 1, hi = 1e18 + 1;
        ll res = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(k, mid, n, c))
            {
                lo = mid + 1;
                res = max(res, mid);
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << res * k << nl;
    }
    return 0;
}