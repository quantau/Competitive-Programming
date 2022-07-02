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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

const ll MAXN = 300005;

ll p[MAXN];
ll c[MAXN];

ll get(ll x)
{
    if (p[x] == x)
    {
        c[x] = 0;
        return x;
    }
    ll boss = get(p[x]);
    c[x] += c[p[x]];
    return p[x] = boss;
}

void union_dsu(ll x, ll y)
{
    p[x] = y;
}

int main()
{
    FASTIO

    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        p[i] = i;
        c[i] = 1;
    }
    while (m--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll a, b;
            cin >> a >> b;
            union_dsu(a, b);
        }
        else
        {
            ll x;
            cin >> x;
            ll boss = get(x);
            cout << c[x] << nl;
            c[boss] = 1;
        }
    }
    return 0;
}