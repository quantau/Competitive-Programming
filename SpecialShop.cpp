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
        ll n, a, b;
        cin >> n >> a >> b;
        ll v1 = n * a / (a + b);
        ll res = 0;
        res = a * (n - v1) * (n - v1) + b * v1 * v1;
        v1 = (n * a + (a + b)) / (a + b);
      //  var(res, v1, 0);
        res = min(a * (n - v1) * (n - v1) + b * v1 * v1, res);
        cout << res << nl;
    }
    return 0;
}