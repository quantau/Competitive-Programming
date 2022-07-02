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
        ll w, h;
        cin >> w >> h;
        ll a[4][2]; //0-> low 1--> high
        for (ll i = 0; i < 4; i++)
        {
            ll k;
            cin >> k;
            a[i][0] = 1e7;
            a[i][1] = 0;
            for (ll j = 0; j < k; j++)
            {
                ll x;
                cin >> x;
                a[i][0] = min(a[i][0], x);
                a[i][1] = max(a[i][1], x);
            }
        }
        ll ans = 0;
        ll val0 = (a[0][1] - a[0][0]) * max({a[2][1], h, a[3][1]});
        ll val1 = (a[1][1] - a[1][0]) * max(h, min(a[2][0], a[3][0]));
        ll val3 = (a[2][1] - a[2][0]) * max({a[0][1], w, a[1][1]});
        ll val4 = (a[3][1] - a[3][0]) * max(w, min(a[0][0], a[2][0]));
        // var(val0, val1, val3, val4);
        cout << max({val0, val1, val3, val4}) << nl;
    }
    return 0;
}