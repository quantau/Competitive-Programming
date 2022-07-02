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

// for prime i sieve[i]=0 else not
const ll MAXN = 1e4 + 1;
ll sieve[MAXN + 5];
vector<ll> primes;

void sieve_of_erathosthenes(ll n = MAXN)
{
    for (ll i = 2; i <= n; i++)
    {
        if (sieve[i])
            continue;
        primes.pb(i);
        for (ll j = i * i; j <= n; j += i)
            sieve[j] = i;
    }
}

int main()
{
    FASTIO
    sieve_of_erathosthenes();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> v[n];
        map<vector<ll>, ll> mp;
        ll res = 1;
        for (ll i = 0; i < n; i++)
        {
            for (auto x : primes)
            {
                ll c = 0;
                if (x * x > a[i])
                {
                    break;
                }
                while (a[i] % x == 0)
                {
                    a[i] /= x;
                    c++;
                }
                if (c % 2)
                {
                    v[i].pb(x);
                }
            }
            if (a[i] > 1)
            {
                v[i].pb(a[i]);
            }
            if (mp.count(v[i]))
            {
                res++;
                mp.clear();
            }
            mp[v[i]] = i;
        }
        cout << res << nl;
    }
    return 0;
}