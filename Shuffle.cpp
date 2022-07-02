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

const ll mod = 998244353;

const ll N = 30000;

ll factorial[N + 1], inverse[N + 1];

unsigned long long power(unsigned long long x, int y)
{
    unsigned long long res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n)
{
    return power(n, mod - 2);
}

unsigned long long nCrFermat(unsigned long long n, int r)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return ((factorial[n] * inverse[r]) % mod * inverse[n - r]) % mod; // (n!)/[(n-r)!(r)!]
}

void pre()
{
    factorial[0] = 1;
    for (ll i = 1; i <= N; i++)
        factorial[i] = (factorial[i - 1] * i) % mod;

    inverse[N] = modInverse(factorial[N]);
    for (ll i = N - 1; i >= 0; i--)
        inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    pre();
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v;
    v.pb(-1);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            v.pb(i);
        }
    }
    v.pb(n);
    if (k == 0 || v.size() - 2 < k)
    {
        cout << 1 << nl;
        return 0;
    }
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << nl;
    ll c = 0;
    for (ll i = k + 1; i < v.size(); i++)
    {

        if (v[i] - 1 < v[i - k - 1] + 1 || k == 0)
            continue;
        c += nCrFermat(v[i] - 1 - (v[i - k - 1] + 1) + 1, k) % mod;
        c %= mod;
        // var(v[i] - 1, v[i - k - 1] + 1, k);
        // cout << c << " ";
    }
    // cout << nl;
    for (ll i = k + 1; i < v.size() - 1; i++)
    {
        c -= nCrFermat(v[i] - 1 - (v[i - k] + 1) + 1, k - 1) % mod;
        c = (mod + c) % mod;
        // var(v[i] - 1, (v[i - k] + 1) + 1, k - 1);
        // cout << c << " ";
    }
    cout << c % mod << nl;
    return 0;
}