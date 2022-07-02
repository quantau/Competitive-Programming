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

    ll n;
    cin >> n;
    ll d[n + 1][n + 1];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }

    ll k;
    cin >> k;
    while (k--)
    {
        ll x, y, w;
        ll res = 0;
        cin >> x >> y >> w;
        d[x][y] = min(d[x][y], w);
        d[y][x] = d[x][y];
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][x] + d[y][j] + d[x][y]);
                d[i][j] = min(d[i][j], d[i][y] + d[x][j] + d[x][y]);
                res += d[i][j];
            }
        }
        cout << res / 2 << " ";
    }
    cout << nl;
    return 0;
}