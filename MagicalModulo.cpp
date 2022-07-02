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

ll n;
ll a[100005];

bool chk(ll a[], ll n, ll x)
{
    vector<bool> vis(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        if (a[i] % x > n)
            break;
        vis[a[i] % x] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
            return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    ll sm = 0;
    ll mn = 1e17;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > n)
        {
            mn = min(mn, a[i]);
        }
        sm += a[i];
    }
    sm -= (n * (n + 1)) / 2;
    if (sm < 0)
    {
        cout << "NO\n";
        return;
    }
    if(sm == 0) {
        if (chk(a, n, n+1))
        {
            cout << "YES " << n+1 << nl;
            return;
        }
    }
    for (ll i = 1; i * i <= sm; i++)
    {
        if (sm % i == 0)
        {
            if (i > mn || i <= n)
            {
                ;
            }
            else if (chk(a, n, i))
            {
                cout << "YES " << i << nl;
                return;
            }
        }
        if (sm % i == 0)
        {
            if ((sm / i) > mn || i <= n)
            {
                ;
            }
            else if (chk(a, n, sm / i))
            {
                cout << "YES " << sm / i << nl;
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}