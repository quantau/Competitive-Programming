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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pii> v(n);
        // ordered_set s;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i].ff;
            v[i].ss = i;
        }
        sort(all(v));
        ll a[n];
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            a[v[i].ss] = i + 1;
            mp[i + 1] = v[i].ff;
        }
        set<ll> s;
        ll res = 0, mn = 1e9 + 7, mx = 0;
        for (ll i = 0; i < n; i++)
        {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            s.insert(a[i]);
            if (*s.rbegin() == s.size())
            {
                res += mp[mx] - mp[mn];
                mx = 0, mn = 1e9 + 7;
            }
        }
        cout << res << nl;
    }
    return 0;
}