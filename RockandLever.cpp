#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << nl;
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        ll mx = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
        }
        sort(all(v));
        ll l = 1;
        ll r = 1;
        ll res = 0;
        ll val = (upper_bound(all(v), r) - lower_bound(all(v), l));
        l *= 2;
        r *= 4;
        r--;
        while (l <= mx)
        {
            dbg(res);
            res += (upper_bound(all(v), r) - lower_bound(all(v), l));
            l *= 2;
            r = (r + 1) * 2 - 1;
        }
        cout << res << nl;
    }
    return 0;
}