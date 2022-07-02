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

ll a[1000001];
ll tree[3][4000004]; //0--> score 1--> ( 2--> )

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[a[strt]][node]++;
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        ll val = min(tree[1][2 * node], tree[2][2 * node + 1]);
        tree[0][node] = tree[0][2 * node] + tree[0][2 * node + 1] + 2 * val;
        tree[1][node] = tree[1][2 * node] + tree[1][2 * node + 1] - val;
        tree[2][node] = tree[2][2 * node] + tree[2][2 * node + 1] - val;
    }
}

pair<ll, pii> query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (lo <= strt && hi >= end)
    {
        return {tree[0][node], {tree[1][node], tree[2][node]}};
    }
    else if (lo > end || hi < strt)
    {
        return {0, {0, 0}};
    }
    else
    {
        ll mid = (strt + end) / 2;
        pair<ll, pii> q1 = query(2 * node, strt, mid, lo, hi);
        pair<ll, pii> q2 = query(2 * node + 1, mid + 1, end, lo, hi);
        pair<ll, pii> p = {0, {0, 0}};
        ll val = min(q1.ss.ff, q2.ss.ss);
        p.ff = q1.ff + q2.ff + 2 * val;
        p.ss.ff = q1.ss.ff + q2.ss.ff - val;
        p.ss.ss = q1.ss.ss + q2.ss.ss - val;
        return p;
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

    string s;
    cin >> s;
    ll n = s.size();
    for (ll i = 0; i < n; i++)
    {
        a[i] = (s[i] == '(' ? 1 : 2);
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << nl;
    build(1, 0, n - 1);
    ll q;
    cin >> q;
    // for (ll i = 1; i < 4 * n; i++)
    // {
    //     cout << i << " ";
    // }
    // cout << nl;
    // for (ll j = 0; j < 3; j++)
    // {
    //     if (j != 0)
    //         cout << " ";
    //     for (ll i = 1; i < 4 * n; i++)
    //     {
    //         cout << tree[j][i] << "  ";
    //     }
    //     cout << nl;
    // }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, --l, --r).ff << nl;
    }
    return 0;
}