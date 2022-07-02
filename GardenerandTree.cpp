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

ll inf = 1e17;

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
        ll n, k;
        cin >> n >> k;
        vector<ll> v[n + 1];
        for (ll i = 0; i < n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        queue<ll> q;
        // bool vis[n + 1];
        ll d[n + 1];
        ll degree[n + 1];
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            // vis[i] = false;
            d[i] = 0;
            degree[i] = v[i].size();
            if (v[i].size() == 1)
            {
                q.push(i);
                // vis[i] = true;
                d[i] = 1;
            }
        }
        while (!q.empty())
        {
            ll scr = q.front();
            q.pop();
            degree[scr]--;
            for (auto x : v[scr])
            {
                degree[x]--;
                if (degree[x] == 1)
                {
                    d[x] = d[scr] + 1;
                    q.push(x);
                }
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            if (d[i] <= k)
            {
                res++;
            }
        }
        cout << n - res << nl;
    }
    return 0;
}