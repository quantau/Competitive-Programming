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
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (n == 2)
        {
            cout << 0 << nl;
            continue;
        }
        else if (n == 3)
        {
            cout << min(a[1] - a[0], a[2] - a[1]) << nl;
            continue;
        }
        ll l = 1, r = n - 2, res = 1e17;
        while (l < r)
        {
            ll lv = a[r] - a[0];
            ll rv = a[n - 1] - a[l];
            // var(lv, rv, 0);
            res = min(res, abs(lv - rv));
            if (lv > rv)
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        ll sm = 0;
        for (ll i = 0; i < n; i++)
        {
            sm += abs(a[n / 2] - a[i]);
        }
        res = min(res, sm - abs(a[n / 2] - a[0]));
        res = min(res, sm - abs(a[n / 2] - a[n - 1]));
        sm = 0;
        for (ll i = 0; i < n; i++)
        {
            sm += abs(a[n / 2 + 1] - a[i]);
        }
        res = min(res, sm - abs(a[n / 2 + 1] - a[0]));
        res = min(res, sm - abs(a[n / 2 + 1] - a[n - 1]));
        sm = 0;
        for (ll i = 0; i < n; i++)
        {
            sm += abs(a[n / 2 - 1] - a[i]);
        }
        res = min(res, sm - abs(a[n / 2 - 1] - a[0]));
        res = min(res, sm - abs(a[n / 2 - 1] - a[n - 1]));
        cout << res << nl;
    }
    return 0;
}