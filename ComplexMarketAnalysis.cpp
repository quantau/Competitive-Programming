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

bool prime[1000001];

void pre()
{
    memset(prime, true, sizeof(prime));
    ll n = 1000000;
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = false;
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, e;
        cin >> n >> e;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll res = 0;
        for (ll i = 0; i < e; i++)
        {
            ll l = 0, r = 0;
            for (ll j = i; j < n; j += e)
            {
                if (a[j] == 1)
                {
                    l++;
                }
                else if (prime[a[j]])
                {
                    for (ll k = j + e; k < n; k += e)
                    {
                        if (a[k] == 1)
                        {
                            r++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    res += (l + 1) * (r + 1) - 1;
                    l = 0, r = 0;
                }
                else
                {
                    l = 0, r = 0;
                }
            }
        }
        cout << res << nl;
    }
    return 0;
}