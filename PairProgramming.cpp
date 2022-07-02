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

bool solve(ll k, ll n, ll m, vector<ll> &res)
{
    ll a[n], b[m];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    ll j = 0;
    for (ll i = 0; i < n; i++)
    {
        while (j < m && b[j] <= a[i])
        {
            if (b[j] == 0)
                k++;
            else if (b[j] > k)
            {
                return false;
            }
            res[i + j] = b[j];
            j++;
        }
        if (a[i] == 0)
            k++;
        else if (a[i] > k)
        {
            return false;
        }
        res[i + j] = a[i];
    }
    while (j < m)
    {
        if (b[j] == 0)
            k++;
        else if (b[j] > k)
        {
            return false;
        }
        res[n + j] = b[j];
        j++;
    }
    return true;
}

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
        ll k, n, m;
        cin >> k >> n >> m;
        vector<ll> res(n + m);
        if (solve(k, n, m, res))
        {
            for (ll i = 0; i < n + m; i++)
            {
                cout << res[i] << " ";
            }
            cout << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}