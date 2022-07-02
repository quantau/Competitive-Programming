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

ll a[200001];
ll tree[800004];

void update(ll node, ll strt, ll end, ll loc)
{
    if (strt == end)
    {
        tree[node]++;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (mid >= loc)
        {
            update(2 * node, strt, mid, loc);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, loc);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (strt >= lo && end <= hi)
    {
        return tree[node];
    }
    else if (strt > hi || end < lo)
    {
        return 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        ll q1 = query(2 * node, strt, mid, lo, hi);
        ll q2 = query(2 * node + 1, mid + 1, end, lo, hi);
        return q1 + q2;
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
    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    vector<ll> loc(n + 1, -1);
    ll r[n + 1];
    for (ll i = 0; i < 2 * n; i++)
    {
        if (loc[a[i]] == -1)
        {
            loc[a[i]] = i;
        }
        else
        {
            update(1, 0, 2 * n - 1, loc[a[i]]);
            r[a[i]] = query(1, 0, 2 * n - 1, loc[a[i]], i) - 1;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << r[i] << " ";
    }
    cout << nl;
    return 0;
}