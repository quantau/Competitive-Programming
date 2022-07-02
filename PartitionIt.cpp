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

    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll num = 1;
        vector<ll> vec;
        vector<ll> v(n + 1, 0);
        vec.pb(1);
        v[1] = 1;
        for (ll i = 2; i <= n; i++)
        {
            if (prime[i] && 2 * i > n)
            {
                num++;
                vec.pb(i);
                v[i] = 1;
            }
        }
        // dbg(num);
        if (k <= num || k >= (n - num))
        {
            cout << "Yes\n";
            if (k <= num)
            {
                for (ll i = 0; i < k; i++)
                {
                    cout << vec[i] << " ";
                }
                cout << nl;
            }
            else
            {
                ll x = n - k;
                for (ll i = 1; i <= n; i++)
                {
                    if (v[i] && x)
                    {
                        x--;
                    }
                    else
                    {
                        cout << i << " ";
                    }
                }
                cout << nl;
            }
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}