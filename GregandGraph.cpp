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
    ll a[n];
    vector<bool> remove(n + 1, 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[n - i - 1];
    }
    vector<ll> res(n, 0);
    for (ll k = 0; k < n; k++)
    {
        ll t = a[k];
        remove[t] = false;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
                //cout << d[i][j] << " ";
                if (!remove[i] && !remove[j])
                    res[n - k - 1] += d[i][j];
            }
        }
        //cout << nl;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << nl;
    return 0;
}