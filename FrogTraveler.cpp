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
ll zero = 0;

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
    ll a[n + 1], drp[n + 1];
    drp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> drp[i];
    }
    ll d[n + 1]; 
    for (ll j = 0; j <= n; j++)
    {
        d[j] = inf;
    }
    pii p[n + 1];
    queue<ll> q;
    q.push(n);
    d[n] = 0;
    p[n] = {-1, -1};
    ll strt = n;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (u == 0)
            break;
        for (ll i = min(u, strt); i >= max(zero, u - a[u]); i--) 
        {
            if (d[i + drp[i]] > d[u] + 1)
            {
                d[i + drp[i]] = d[u] + 1;
                q.push(i + drp[i]);
                p[i + drp[i]] = {u, i};
            }
        }
        strt = min(strt, max(zero, u - a[u]));
    }
    ll dis = d[0];
    if (dis == inf)
    {
        cout << -1 << nl;
    }
    else
    {
        cout << d[0] << nl;
        vector<ll> res;
        ll par = 0;
        while (p[par].ss != -1)
        {
            res.pb(p[par].ss);
            par = p[par].ff;
        }
        reverse(all(res));
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << nl;
    }
    return 0;
}