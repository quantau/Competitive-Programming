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

    ll inf = 1e17;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll b[n - 1];
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        ll ans = inf;
        ll money = 0;
        ll days = 0;
        ll num = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            ans = min(ans, days + max(num, ((c - money) + (a[i] - 1)) / a[i]));
            ll delta = max(num, ((b[i] - money) + (a[i] - 1)) / a[i]);
            days += delta + 1;
            money += delta * a[i] - b[i];
            // var(ans, delta, money, days);
        }
        ans = min(ans, days + max(num, ((c - money) + (a[n - 1] - 1)) / a[n - 1]));
        cout << ans << nl;
    }
    return 0;
}