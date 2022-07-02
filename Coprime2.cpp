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

ll sieve[100001];

void sieve_of_erathosthenes(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (sieve[i])
            continue;
        for (ll j = 2 * i; j <= n; j += i)
            sieve[j] = i;
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> p(100001, 0);
    for (ll i = 0; i < n; i++)
    {
        ll num = a[i];
        for (ll j = 2; j * j <= num; j++)
        {
            while (num % j == 0)
            {
                num /= j;
                p[j] = 1;
            }
        }
        if (num > 1)
        {
            p[num] = 1;
        }
    }
    for (ll i = 2; i <= m; i++)
    {
        if (sieve[i])
            continue;
        if (!p[i])
            continue;
        for (ll j = 2 * i; j <= m; j += i)
        {
            p[j] = 1;
        }
    }
    ll res = 0;
    vector<ll> r;
    for (ll i = 1; i <= m; i++)
    {
        if (!p[i])
        {
            r.pb(i);
            res++;
        }
    }
    cout << res << nl;
    for (ll i = 0; i < res; i++)
    {
        cout << r[i] << nl;
    }
    return 0;
}