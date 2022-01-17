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
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i].ff;
            mp[v[i].ff] = 0;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i].ss;
        }
        sort(all(v));
        for (ll i = 0; i < n; i++)
        {
            auto it = mp.lower_bound(v[i].ff - v[i].ss + 1);
            (*it).ss++;
        }
        ll res = 0, curr = 0, so_far = 0;
        for (ll i = 0; i < n; i++)
        {
            so_far += mp[v[i].ff];
            if (curr)
            {
                curr = max(v[i].ss, curr + (v[i].ff - v[i - 1].ff));
            }
            else
            {
                curr = v[i].ss;
            }
            if (so_far <= i + 1)
            {
                res += (curr * (curr + 1)) / 2;
                curr = 0;
            }
        }
        cout << res << nl;
    }
    return 0;
}