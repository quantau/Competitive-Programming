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

ll n;
ll h[200001];

bool ok(ll x)
{
    vector<ll> val(n, 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        // var(h[i],0,0);
        if (h[i] + val[i] < x)
            return false;
        if (i - 1 >= 1)
        {
            val[i - 1] += max((ll)0, (h[i] - max((ll)0, x - val[i])) / 3);
        }
        if (i - 2 >= 0)
        {
            val[i - 2] += max((ll)0, 2 * ((h[i] - max((ll)0, x - val[i])) / 3));
        }
    }
    return true;
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
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        ll lo = 1, hi = 1e9;
        ll res = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid))
            {
                res = max(res, mid);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << res << nl;
    }
    return 0;
}