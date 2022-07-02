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

const int MAXN = 2 * 1e5 + 1;

ll fact[MAXN];
ll mod = 1e9 + 7;

ll find_pow(ll x, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return find_pow(x * x, n / 2) % mod;
    }
    else
    {
        return ((x % mod) * (find_pow(x * x, (n - 1) / 2) % mod)) % mod;
    }
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

void modInverse(int a, int m)
{
    // If a and m are relatively prime, then modulo
    // inverse is a^(m-2) mode m
    cout << "Modular multiplicative inverse is "
         << power(a, m - 2, m);
}

// To compute x^y under modulo m

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << ((fact[2 * n] % mod) * (500000004 % mod)) % mod << nl;
        //  var((fact[n] % mod), (find_pow(2, mod - 2)) % mod, 0);
    }
    cout << modInverse(2, mod);
    return 0;
}