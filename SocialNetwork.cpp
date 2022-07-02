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

vector<ll> p(1001, -1);

ll get(ll x)
{
    if (p[x] < 0)
        return x;
    p[x] = get(p[x]);
    return p[x];
}

void union_dsu(ll x, ll y, multiset<ll> &s)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (-p[x] < -p[y])
        swap(x, y);
    s.erase(s.find(p[y]));
    s.erase(s.find(p[x]));
    s.insert(p[y] + p[x]);
    p[x] += p[y];
    p[y] = x;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, d;
    cin >> n >> d;
    multiset<ll> s;
    for (ll i = 0; i < n; i++)
    {
        s.insert(-1);
    }
    ll c = 1;
    for (ll i = 0; i < d; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (get(x) == get(y))
        {
            c++;
        }
        else
        {
            union_dsu(x, y, s);
        }
        ll res = 0;
        auto it = s.begin();
        for (ll i = 0; i < c; i++)
        {
            res += (*it);
            it++;
        }
        cout << -res - 1 << nl;
    }
    return 0;
}