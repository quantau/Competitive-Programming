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
ll suff[400004];
ll pref[400004];
ll mx[400004];

void build(ll node, ll strt, ll en)
{
    if (strt == en)
    {
        tree[node] = a[strt];
        pref[node] = max((ll)0, a[strt]);
        suff[node] = max((ll)0, a[strt]);
        mx[node] = max({tree[node], pref[node], suff[node]});
    }
    else
    {
        ll mid = (en + strt) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, en);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
        pref[node] = max(pref[2 * node], tree[2 * node] + pref[2 * node + 1]);
        suff[node] = max(suff[2 * node + 1], tree[2 * node + 1] + suff[2 * node]);
        mx[node] = max({mx[2 * node], mx[2 * node + 1], suff[2 * node] + pref[2 * node + 1]});
    }
}

void update(ll node, ll strt, ll en, ll ind, ll val)
{
    if (strt == en)
    {
        tree[node] = val;
        pref[node] = max((ll)0, val);
        suff[node] = max((ll)0, val);
        mx[node] = max({tree[node], pref[node], suff[node]});
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
        pref[node] = max(pref[2 * node], tree[2 * node] + pref[2 * node + 1]);
        suff[node] = max(suff[2 * node + 1], tree[2 * node + 1] + suff[2 * node]);
        mx[node] = max({mx[2 * node], mx[2 * node + 1], suff[2 * node] + pref[2 * node + 1]});
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
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    cout << mx[1] << nl;
    while (m--)
    {
        ll index, val;
        cin >> index >> val;
        update(1, 0, n - 1, index, val);
        cout << mx[1] << nl;
    }
    return 0;
}