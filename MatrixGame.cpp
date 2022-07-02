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
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        ll r = 0;
        for (ll i = 0; i < n; i++)
        {
            ll g[m];
            g[m - 1] = a[i][m - 1];
            for (ll j = m - 2; j >= 0; j--)
            {
                if (a[i][j] <= g[j + 1])
                {
                    g[j] = a[i][j] - 1;
                }
                else
                {
                    g[j] = a[i][j];
                }
            }
            r = r ^ g[0];
        }
        if (r)
        {
            cout << "FIRST\n";
        }
        else
        {
            cout << "SECOND\n";
        }
    }
    return 0;
}