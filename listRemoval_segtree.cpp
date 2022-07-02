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
// vector<ll> a(200001, 1);
ll tree[800001];

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[node] = 1;
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, ll strt, ll end, ll sum)
{
    if (strt == end)
    {
        return strt;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (sum <= tree[2 * node])
        {
            query(2 * node, strt, mid, sum);
        }
        else
        {
            query(2 * node + 1, mid + 1, end, sum - tree[2 * node]);
        }
    }
}

void update(ll node, ll strt, ll end, ll sum)
{
    if (strt == end)
    {
        tree[node] = 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (sum <= tree[2 * node])
        {
            update(2 * node, strt, mid, sum);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, sum - tree[2 * node]);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
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
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //vector<ll> a(n, 1);
    build(1, 0, n - 1);
    for (ll i = 0; i < n; i++)
    {
        ll q;
        cin >> q;
        cout << arr[query(1, 0, n - 1, q)] << " ";
        update(1, 0, n - 1, q);
    }
    return 0;
}