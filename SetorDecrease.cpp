#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
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
        ll n, k;
        cin >> n >> k;
        ll a[n], sm = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sm += a[i];
        }
        sort(a, a + n);
        sm -= a[0];
        ll res = max((ll)0, a[0] - (k - sm));
        ll mov = 1;
        for (ll i = n - 1; i > 0; i--)
        {
            mov++;
            sm -= a[i];
            ll val = a[0] - (k - sm) / mov + ((k - sm) < 0 && (k - sm) % mov ? 1 : 0);
            // dbg(val);
            res = min(res, max((ll)0, val) + mov - 1);
            // var(mov, val, res, max((ll)0, val) + mov - 1);
        }
        cout << res << nl;
    }
    return 0;
}