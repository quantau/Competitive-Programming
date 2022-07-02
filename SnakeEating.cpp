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
        ll n, q;
        cin >> n >> q;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll pref[n];
        sort(all(v));
        for (ll i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + v[i];
        }
        while (q--)
        {
            ll val;
            cin >> val;
            ll res = 0;
            ll in = upper_bound(all(v), val - 1) - v.begin() - 1;
            res += n - 1 - in;
            ll lo = 0, hi = in;
            ll r = hi;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                if (val * (in - mid) - (pref[in] - pref[mid]) <= mid + 1)
                {
                    r = min(r, mid);
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            cout << res + (in - r) << nl;
        }
    }
    return 0;
}