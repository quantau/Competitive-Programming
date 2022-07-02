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

//efficient way to find gcd
ll get_gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return get_gcd(b, a % b);
    }
}

bool solve(ll a[], ll n)
{
    for (ll i = 1; i < n; i++)
    {
        if (get_gcd(a[i], a[i - 1]) != a[i])
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (solve(a, n))
        {
            for (ll i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << nl;
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}
