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

vector<set<ll>> adj(300001);
bool vis[300001][2];
bool parity[300001];

void dfs(ll node, ll &gain, ll i)
{
    vis[node][i] = true;
    for (auto x : adj[node])
    {
        if (vis[x][i])
            continue;
        if (!parity[node])
        {
            parity[x] = 1;
            gain++;
        }
        else
        {
            parity[x] = 0;
        }
        dfs(x, gain, i);
    }
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
    set<pii> st;
    set<ll> s;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x == i)
        {
            s.insert(x);
            continue;
        }
        st.insert({x, i});
    }
    // for (auto x : st)
    // {
    //     cout << x.ff << " " << x.ss << endl;
    // }
    // for (auto x : s)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    set<pii> temp;
    for (auto &x : st) //check
    {
        //cout << x.ff << " " << x.ss << endl;
        if (s.find(x.ff) != s.end())
        {
            continue;
        }
        temp.insert(x);
    }
    st = temp;
    s.clear();
    // for (auto x : st)
    // {
    //     cout << x.ff << " " << x.ss << endl;
    // }
    for (auto x : st)
    {
        s.insert(x.ff);
        s.insert(x.ss);
        adj[x.ff].insert(x.ss);
        adj[x.ss].insert(x.ff);
    }
    ll res = 0;
    for (auto x : s)
    {
        if (!vis[x][0])
        {
            ll gain = 0;
            dfs(x, gain, 0);
            ll gain2 = 0;
            ll node = (*adj[x].begin());
            dfs(node, gain2, 1);
            res += max(gain, gain2);
        }
    }
    cout << res << nl;
    return 0;
}