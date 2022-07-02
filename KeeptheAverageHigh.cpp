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
        ll n, x;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> x;
        for (ll i = 0; i < n; i++)
        {
            a[i] -= x;
        }
        vector<ll> mark(n, 1);
        ll ans = n;
        for (ll i = 0; i < n; i++)
        {
            ll sum = a[i];
            for (ll j = i - 1; j >= 0 && i - j + 1 <= 3; j--)
            {
                sum += a[j];
                if (!mark[j])
                {
                    break;
                }
                else if (sum < 0)
                {
                    mark[i] = 0;
                    ans--;
                    break;
                }
            }
        }
        cout << ans << nl;
    }
    return 0;
}