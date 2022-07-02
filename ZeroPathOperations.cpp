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

vector<ll> v[100001];

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
        for (ll i = 0; i <= n; i++)
        {
            v[i].clear();
        }
        for (ll i = 0; i < n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        ll val[n];
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            val[i] = x;
        }
        if (n == 1)
        {
            cout << 0 << nl;
            continue;
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (v[i].size() == 1)
                continue;
            if (val[i] == 0)
                continue;
            ans++;
        }
        cout << ans << nl;
    }
    return 0;
}