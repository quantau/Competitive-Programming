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

vector<ll> v[1001];
ll vis[1001];

void dfs(ll node, ll comp)
{
    vis[node] = comp;
    for (auto x : v[node])
    {
        if (vis[node])
            continue;
        dfs(x, comp);
    }
}

bool dfs2(ll node, ll parent, vector<bool> &visited)
{
    visited[node] = true;
    for (auto x : v[node])
    {
        if (visited[x] && x != parent)
        {
            return false;
        }
        return dfs2(x, node, visited);
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

    ll n;
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll in;
    for (ll i = 1; i <= n; i++)
    {
        vector<bool> visited(n + 1, false);
        if (dfs2(i, 0, visited))
        {
            in = i;
            break;
        }
    }
    dbg(in);
    ll connected_comps_count = 0;
    vector<pii> brk;
    vector<ll> ind;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (i != in)
            {
                brk.pb({i, v[i][0]});
                ind.pb(i);
            }
            connected_comps_count++;
            dfs(i, connected_comps_count);
        }
    }
    ind.pb(in);
    if (connected_comps_count == 1)
    {
        cout << 0 << nl;
        return 0;
    }
    cout << connected_comps_count << nl;
    for (ll i = 0; i < brk.size(); i++)
    {
        cout << brk[i].ff << " " << brk[i].ss << " " << ind[i] << " " << ind[i + 1] << nl;
    }
    return 0;
}