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
vector<ll> xmx(1001);
vector<ll> xmn(1001);
vector<ll> ymx(1001);
vector<ll> ymn(1001);

ll get_dsu(ll x)
{
    if (p[x] < 0)
        return x;
    p[x] = get_dsu(p[x]);
    return p[x];
}

void union_dsu(ll x, ll y)
{
    x = get_dsu(x);
    y = get_dsu(y);
    if (x == y)
        return;
    if (-p[x] < -p[y])
        swap(x, y);
    p[x] += p[y];
    p[y] = x;
    xmx[x] = max(xmx[x], xmx[y]);
    xmn[x] = min(xmn[x], xmn[y]);
    ymx[x] = max(ymx[x], ymx[y]);
    ymn[x] = min(ymn[x], ymn[y]);
}

ll dis(pii p1, pii p2)
{
    ll dx = (p1.ff - p2.ff);
    ll dy = (p1.ss - p2.ss);
    return (dx * dx + dy * dy);
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        xmx.clear(), xmn.clear(), ymx.clear(), ymn.clear();
        ll n, X, Y;
        cin >> X >> Y;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            p[i] = -1;
        }
        vector<pair<pii, ll>> v(n);
        for (ll i = 0; i < n; i++)
        {
            ll x1, y1, r;
            cin >> x1 >> y1 >> r;
            v[i] = {{x1, y1}, r};
        }
        for (ll i = 0; i < n; i++)
        {
            ll x1 = v[i].ff.ff, y1 = v[i].ff.ss, r = v[i].ss;
            xmx[i] = x1 + r;
            xmn[i] = x1 - r;
            ymx[i] = y1 + r;
            ymn[i] = y1 - r;
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                ll die = dis(v[i].ff, v[j].ff);
                ll die2 = (v[i].ss + v[j].ss) * (v[i].ss + v[j].ss);
                if (die <= die2)
                {
                    union_dsu(i, j);
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (p[i] < 0)
            {
                if ((xmx[i] >= X && xmn[i] <= 0) || (ymx[i] >= Y && ymn[i] <= 0))
                {
                    cout << "NO\n";
                    return 0;
                }
                if ((xmx[i] >= X && ymx[i] >= Y) || (xmn[i] <= 0 && ymn[i] <= 0))
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
        cout<<"YES\n";
    }
    return 0;
}