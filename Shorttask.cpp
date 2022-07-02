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

const int MAXN = 1e7;
const int inf = 1e7 + 9;
int a[MAXN + 5];
vector<int> b(MAXN + 5, inf);

void pre()
{
    for (ll i = 1; i <= MAXN; i++)
    {
        for (ll j = i; j <= MAXN; j += i)
        {
            a[j] += i;
        }
    }
    for (int i = 1; i <= MAXN; i++)
    {
        if (a[i] > MAXN)
            continue;
        b[a[i]] = min(b[a[i]], i);
    }
}

int main()
{
    FASTIO
    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        ll c;
        cin >> c;
        cout << (b[c] == inf ? -1 : b[c]) << nl;
    }
    return 0;
}