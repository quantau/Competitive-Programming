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

    ll n, m;
    cin >> n >> m;
    ll a[n + 1];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = 1e9;
    sort(a, a + n);
    vector<ll> v;
    for (ll i = 0; i < m; i++)
    {
        ll x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1)
        {
            v.pb(x2);
        }
    }
    sort(all(v));
    ll ans = n + m;
    for (ll i = 0; i <= n; i++)
    {
        ll val = i;
        val += (v.size() - (lower_bound(all(v), a[i]) - v.begin()));
        ans = min(ans, val);
    }
    cout << ans << nl;
    return 0;
}