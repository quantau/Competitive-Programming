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

//for prime i sieve[i]=0 else not
bool prime[100001];

void pre()
{
    memset(prime, true, sizeof(prime));
    ll n = 100000;
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
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

    sieve_of_erathosthenes(100000);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll num = n, pow = 0;
        // sort(all(prim));
        for (auto x : prim)
        {
            if (x * x > n)
                break;
            ll val = n, cont = 0;
            while (val % x == 0)
            {
                cont++;
                val /= x;
            }
            if (cont > pow)
            {
                pow = cont;
                num = x;
            }
        }
        cout << num << nl;
    }
    return 0;
}