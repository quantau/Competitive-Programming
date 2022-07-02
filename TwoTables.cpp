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
        ll H, W;
        cin >> W >> H;
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double w, h;
        cin >> w >> h;
        if (h + (y2 - y1) > H && w + (x2 - x1) > W)
        {
            cout << -1 << nl;
            continue;
        }
        double res = 1e14;
        if (w + (x2 - x1) <= W)
        {
            res = min({res, max(w, x1) - x1, x2 - min(W - w, x2)});
        }
        if (h + (y2 - y1) <= H)
        {
            res = min({res, max(h, y1) - y1, y2 - min(H - h, y2)});
        }
        cout << setprecision(9) << res << nl;
    }
    return 0;
}