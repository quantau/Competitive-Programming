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

        ll n, d;
        cin >> n >> d;
        ll inf = 1e17;
        ll ds[n];
        for (ll i = 0; i < n; i++)
        {
            ds[i] = inf;
        }
        vector<ll> v[n];
        queue<ll> q;
        int a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            int j = (i + d) % n;
            v[i].pb(j);
            if (!a[i])
            {
                q.push(i);
                ds[i] = 0;
            }
        }
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto x : v[u])
            {
                if (ds[x] > ds[u] + 1)
                {
                    ds[x] = ds[u] + 1;
                    q.push(x);
                }
            }
        }
        // bool b = false;
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] && ds[i] == inf)
            {
                res = -1;
                break;
            }
            else if (a[i])
            {
                res = max(res, ds[i]);
            }
        }
        cout << res << nl;
    }
    return 0;
}