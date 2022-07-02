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
ll tree[800001];

ll find_pow(ll x, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return find_pow(x * x, n / 2);
    }
    else
    {
        return x * find_pow(x * x, (n - 1) / 2);
    }
}

bool check(ll num)
{
    while (num % 4 == 0)
    {
        num /= 4;
    }
    return num == 1;
}

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[node] = a[strt];
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        if (check(end - strt + 1))
        {
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
        else
        {
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        }
    }
}

void update(ll node, ll strt, ll end, ll in, ll val)
{
    if (strt == end)
    {
        if (strt != in)
            return;
        tree[node] = val;
    }
    else if (end < in || strt > in)
    {
        return;
    }
    else
    {
        ll mid = (strt + end) / 2;
        update(2 * node, strt, mid, in, val);
        update(2 * node + 1, mid + 1, end, in, val);
        if (check(end - strt + 1))
        {
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
        else
        {
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        }
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

    ll n, m;
    cin >> n >> m;
    n = find_pow(2, n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    // for (ll i = 1; i < 4 * n; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    // cout << endl;
    while (m--)
    {
        ll p, b;
        cin >> p >> b;
        update(1, 0, n - 1, --p, b);
        cout << tree[1] << nl;
        // for (ll i = 1; i < 4 * n; i++)
        // {
        //     cout << tree[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}