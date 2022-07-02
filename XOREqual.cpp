#include <bits/stdc++.h>
#define sz(val) val.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(val, y, z) cout << val << " " << y << " " << z << endl;
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

    //freopen("input.tvalt","r",stdin);
    //freopen("output.tvalt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, val;
        cin >> n >> val;
        map<ll, ll> mp;
        ll res = 0, steps = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
            res = max(res, mp[x]);
        }
        vector<pii> v;
        for (auto x : mp)
        {
            v.pb({x.ss, x.ff});
        }
        sort(all(v));
        for (auto x : v)
        {
            ll num = x.ss ^ val;
            if (num == x.ss)
                continue;
            if (res < mp[num] + x.ff)
            {
                res = mp[num] + x.ff;
                steps = x.ff;
            }
        }
        cout << res << " " << steps << nl;
    }
    return 0;
}