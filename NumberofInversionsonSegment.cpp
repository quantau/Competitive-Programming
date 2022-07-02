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

ll a[100001];
ll inv[400004];
ll inv2[400004];
ll c[400004][41];
ll q[400004][41];

void build(ll node, ll strt, ll en)
{
    if (strt == en)
    {
        inv[node] = 0;
        c[node][a[strt]] = 1;
    }
    else
    {
        ll mid = (en + strt) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, en);
        ll sum = 0;
        for (ll i = 1; i <= 40; i++)
        {
            c[node][i] = c[2 * node][i] + c[2 * node + 1][i];
            sum += c[2 * node][i];
        }
        ll num = 0;
        for (ll i = 1; i <= 40; i++)
        {
            sum -= c[2 * node][i];
            num += sum * c[2 * node + 1][i];
        }
        inv[node] = inv[2 * node] + inv[2 * node + 1] + num;
    }
}

void update(ll node, ll strt, ll en, ll ind, ll val)
{
    if (strt == en)
    {
        c[node][a[strt]] = 0;
        a[strt] = val;
        c[node][a[strt]] = 1;
    }
    else
    {
        ll mid = (strt + en) / 2;
        if (ind <= mid)
            update(2 * node, strt, mid, ind, val);
        else
        {
            update(2 * node + 1, mid + 1, en, ind, val);
        }
        ll sum = 0;
        for (ll i = 1; i <= 40; i++)
        {
            c[node][i] = c[2 * node][i] + c[2 * node + 1][i];
            sum += c[2 * node][i];
        }
        ll num = 0;
        for (ll i = 1; i <= 40; i++)
        {
            sum -= c[2 * node][i];
            num += sum * c[2 * node + 1][i];
        }
        inv[node] = inv[2 * node] + inv[2 * node + 1] + num;
    }
}

ll query(ll node, ll strt, ll en, ll lo, ll hi)
{
    if (lo <= strt && hi >= en)
    {
        inv2[node] = inv[node];
        for (ll i = 1; i <= 40; i++)
        {
            q[node][i] = c[node][i];
        }
        return inv[node];
    }
    else if (lo > en || hi < strt)
    {
        inv2[node] = 0;
        for (ll i = 1; i <= 40; i++)
        {
            q[node][i] = 0;
        }
        return 0;
    }
    ll mid = (strt + en) / 2;
    ll q1 = query(2 * node, strt, mid, lo, hi);
    ll q2 = query(2 * node + 1, mid + 1, en, lo, hi);
    ll sum = 0;
    for (ll i = 1; i <= 40; i++)
    {
        q[node][i] = q[2 * node][i] + q[2 * node + 1][i];
        sum += q[2 * node][i];
    }
    ll num = 0;
    for (ll i = 1; i <= 40; i++)
    {
        sum -= q[2 * node][i];
        num += sum * q[2 * node + 1][i];
    }
    inv2[node] = inv2[2 * node] + inv2[2 * node + 1] + num;
    return inv2[node];
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            cout << query(1, 0, n - 1, x, y) << nl;
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            x--;
            update(1, 0, n - 1, x, y);
        }
    }

    return 0;
}