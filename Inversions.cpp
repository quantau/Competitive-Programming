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
ll tree[400004];

void update(ll node, ll strt, ll en, ll val)
{
    if (strt == en)
    {
        tree[node]++;
    }
    else
    {
        ll mid = (strt + en) / 2;
        if (val <= mid)
        {
            update(2 * node, strt, mid, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, en, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, ll strt, ll en, ll lo, ll hi)
{
    if (strt >= lo && en <= hi)
    {
        return tree[node];
    }
    else if (strt > hi || en < lo)
    {
        return 0;
    }
    else
    {
        ll mid = (strt + en) / 2;
        ll q1 = query(2 * node, strt, mid, lo, hi);
        ll q2 = query(2 * node + 1, mid + 1, en, lo, hi);
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
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        update(1, 0, n - 1, a[i]);
        cout << query(1, 0, n - 1, a[i] + 1, n - 1) << " ";
    }
    return 0;
}