#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << nl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

ll a[1000001];
ll tree[4000004];

void update(ll node, ll strt, ll en, ll ind, ll val)
{
    if (strt == en)
    {
        tree[node] = 1;
        a[strt] = val;
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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void erase(ll node, ll strt, ll en, ll val)
{
    if (strt == en)
    {
        // var(node, strt, val, 'f');
        tree[node] = 0;
        a[strt] = -1;
    }
    else
    {
        ll mid = (strt + en) / 2;
        // var(tree[2 * node], strt, en, 'g');
        if (tree[2 * node] >= val)
        {
            erase(2 * node, strt, mid, val);
        }
        else
        {
            erase(2 * node + 1, mid + 1, en, val - tree[2 * node]);
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

    ll n, m;
    cin >> n >> m;
    ll b[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    ll sz = 0;
    ll N = n;
    while (n--)
    {
        ll x;
        cin >> x;
        if (x == -1)
        {
            for (ll i = 0; i < m; i++)
            {
                // var(tree[1], b[i], i, 'c');
                if (tree[1] < b[i] - i)
                    break;
                erase(1, 1, N, b[i] - i);
            }
        }
        else
        {
            sz++;
            update(1, 1, N, sz, x);
        }
        // dbg(n);
        // for (ll i = 1; i <= sz; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << nl;
    }
    bool bc = true;
    for (ll i = 1; i <= sz; i++)
    {
        if (a[i] != -1)
        {
            bc = false;
            cout << a[i];
        }
    }
    if (bc)
    {
        cout << "Poor stack!\n";
    }
    return 0;
}