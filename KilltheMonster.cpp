#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << nl;
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
        ll hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        ll res = k + 1;
        for (ll i = 0; i <= k; i++)
        {
            ll health = hc + i * a;
            ll moves = (health + dm - 1) / dm;
            ll damage = (hm + moves - 1) / moves;
            damage = max(damage, dc);
            // dbg(damage);
            if (w == 0 && damage <= dc)
            {
                res = min(res, i);
            }
            else if (w > 0)
            {
                res = min(res, i + (damage - dc + w - 1) / w);
            }
        }
        // dbg(res);
        cout << (res <= k ? "YES\n" : "NO\n");
    }
    return 0;
}