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

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll primes = 0;
        ll val = m;
        for (ll i = 2; i * i <= m; i++)
        {
            bool b = false;
            while (val % i == 0)
            {
                b = true;
                val /= i;
            }
            primes += b;
        }
        if (val > 1)
        {
            primes++;
        }
        if (m == 1)
        {
            cout << 0 << nl;
            continue;
        }
        // cout << primes << nl;
        bool done = false;
        for (ll i = primes; i >= 1; i--)
        {
            if (n % i == 0)
            {
                done = true;
                cout << i << nl;
                break;
            }
        }
        if (!done)
        {
            cout << 0 << nl;
        }
    }
    return 0;
}