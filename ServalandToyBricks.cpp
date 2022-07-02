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

    ll n, m, height;
    cin >> n >> m >> height;
    ll a[m], b[n], h[n][m];
    for (ll i = 0; i < m; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> h[i][j];
        }
    }
    // ll res[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (h[i][j])
            {
                cout << min(a[j], b[i]) << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << nl;
    }
    return 0;
}