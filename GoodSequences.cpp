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

const int MAXN = 1e5 + 1;

//for prime i sieve[i]=0 else not
ll sieve[MAXN];
vector<ll> primes;

void sieve_of_erathosthenes(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            continue;
        }
        primes.pb(i);
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

    ll n;
    cin >> n;
    ll a[n];
    ll mx = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    sieve_of_erathosthenes(mx + 1);
    // for (ll i = 0; i < primes.size(); i++)
    // {
    //     cout << primes[i] << " ";
    // }
    // cout << nl;
    vector<ll> occ(mx + 1, -1);
    ll dp[n];
    for (ll i = 0; i < n; i++)
    {
        dp[i] = 1;
        ll num = a[i];
        for (auto x : primes)
        {
            bool b = true;
            if (x * x > num)
                break;
            while (num % x == 0)
            {
                if (occ[x] != -1 && b)
                {
                    dp[i] = max(dp[i], dp[occ[x]] + 1);
                }
                b = false;
                occ[x] = i;
                num /= x;
            }
        }
        if (num > 1)
        {
            if (occ[num] != -1)
            {
                dp[i] = max(dp[i], dp[occ[num]] + 1);
            }
            occ[num] = i;
            num /= num;
        }
    }
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        res = max(dp[i], res);
    }
    cout << res << nl;
    return 0;
}