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
const int MAXN = 1e6 + 5;
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

ll calc(ll z)
{
    ll cont = 0;
    for (auto x : primes)
    {
        if (x * x > z)
        {
            break;
        }
        while (z % x == 0)
        {
            cont++;
            z /= x;
        }
    }
    if (z > 1)
    {
        cont++;
    }
    return cont;
}

int main()
{
    FASTIO

    sieve_of_erathosthenes();
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        if (k > 30)
        {
            cout << "NO\n";
            continue;
        }
        ll g = __gcd(a, b);
        ll a1 = a / g, ll b1 = b / g;
        ll x = calc(g), y = calc(a1), z = calc(b1);
        ll mn = min((ll)2, y + z);
        if (k >= mn && k <= z + y)
        {
            cout << "YES\n";
        }
        else if (k == z + y + 1 || k > 2 * x + y + z)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}