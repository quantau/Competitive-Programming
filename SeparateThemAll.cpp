#include <bits/stdc++.h>
#define sz(x) x.size()
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
// #define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define on_bit(x) __builtin_popcountint(x)
#define msb(x) (63 - __builtin_clzint(x))
#define lsb(x) __builtin_ctzint(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<set<int>> adj(n + 4);
        vector<set<int>> adj1(n + 4);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj1[u].insert(v);
            adj1[v].insert(u);
        }
        q++;
        for (int chk = 1; chk <= q; chk++)
        {
            adj = adj1;
            if (chk > 1)
            {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                adj[a].erase(b);
                adj[b].erase(a);
                adj[c].insert(d);
                adj[d].insert(c);
            }
            queue<int> q;
            for (int i = 1; i <= n; i++)
            {
                if (adj[i].size() == 1)
                {
                    q.push(i);
                }
            }
            int res = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (adj[u].empty())
                {
                    continue;
                }
                int v = *(adj[u].begin());
                res += adj[v].size();
                adj[u].erase(v);
                adj[v].erase(u);
                if (adj[v].size() == 1)
                {
                    q.push(v);
                }
            }
            cout << res << nl;
        }
    }
    return 0;
}