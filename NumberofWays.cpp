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

const ll MAXN = 1e5 + 1;
bool sieve[MAXN];
vector<ll> p;

void sieve_of_erathosthenes(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (sieve[i])
            continue;
        p.pb(i);
        for (ll j = 2 * i; j <= n; j += i)
            sieve[j] = true;
    }
}

bool solve()
{
    ll a, b;
    cin >> a >> b;
    set<ll> s;
    for (auto x : p)
    {
        if (x * x > b)
        {
            break;
        }
        while (b % x == 0)
        {
            s.insert(x);
            b /= x;
        }
    }
    if (b > 1)
    {
        s.insert(b);
    }
    for (auto x : p)
    {
        if (x * x > a)
        {
            break;
        }
        while (a % x == 0)
        {
            if (s.find(x) == s.end())
                return false;
            a /= x;
        }
    }
    if (a > 1)
    {
        if (s.find(a) == s.end())
            return false;
    }
    return true;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    sieve_of_erathosthenes(MAXN);
    ll t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}