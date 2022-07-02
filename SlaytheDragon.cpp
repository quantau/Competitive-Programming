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

    ll zero = 0;
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(all(v));
    ll m;
    cin >> m;
    while (m--)
    {
        ll a, d;
        cin >> d >> a;
        ll in = lower_bound(all(v), d) - v.begin();
        if (in == 0)
        {
            cout << max(zero, a - (sum - v[in])) << nl;
        }
        else if (in == n)
        {
            cout << d - v[in - 1] + max(zero, a - (sum - v[in - 1])) << nl;
        }
        else
        {
            cout << min(d - v[in - 1] + max(zero, a - (sum - v[in - 1])), max(zero, a - (sum - v[in]))) << nl;
        }
    }
    return 0;
}