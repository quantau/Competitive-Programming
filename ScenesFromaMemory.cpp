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

//finds whether the number is prime or not
bool is_prime(ll x)
{
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    for (ll i = 0; i < k; i++)
    {
        if (!is_prime(s[i] - '0'))
        {
            cout << 1 << "\n"
                 << s[i] << nl;
            return;
        }
    }
    cout << 2 << nl;
    for (ll i = 0; i < k; i++)
    {
        for (ll j = i + 1; j < k; j++)
        {
            ll num = 10 * (s[i] - '0') + (s[j] - '0');
            if (!is_prime(num))
            {
                cout << num << nl;
                return;
            }
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

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}