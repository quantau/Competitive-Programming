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
        ll n;
        cin >> n;
        ll a;
        ll odd = 0, even = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a;
            if (a % 2)
                odd++;
            else
            {
                even++;
            }
        }
        cout << min(odd, n / 2) + min(even, (n + 1) / 2) << nl;
    }
    return 0;
}