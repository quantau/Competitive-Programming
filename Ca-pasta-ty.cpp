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

const ll MAXN = 1e6 + 1;
ll zero = 0;
ll s[MAXN], x[MAXN], y[MAXN];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("capastaty_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for (ll q = 1; q <= t; q++)
    {
        ll n, k;
        cin >> n >> k;
        ll a[3], b[3], c[3], d[3];
        for (ll i = 0; i < k; i++)
        {
            cin >> s[i];
        }
        cin >> a[0] >> b[0] >> c[0] >> d[0];
        for (ll i = 0; i < k; i++)
        {
            cin >> x[i];
        }
        cin >> a[1] >> b[1] >> c[1] >> d[1];
        for (ll i = 0; i < k; i++)
        {
            cin >> y[i];
        }
        cin >> a[2] >> b[2] >> c[2] >> d[2];
        while (k < n)
        {
            s[k] = ((a[0] % d[0] * s[k - 2] % d[0]) % d[0] + (b[0] % d[0] * s[k - 1] % d[0]) % d[0] + (c[0] % d[0]) % d[0]) % d[0];
            x[k] = ((a[1] % d[1] * x[k - 2] % d[1]) % d[1] + (b[1] % d[1] * x[k - 1] % d[1]) % d[1] + c[1]) % d[1];
            y[k] = ((a[2] % d[2] * y[k - 2] % d[2]) % d[2] + (b[2] % d[2] * y[k - 1] % d[2]) % d[2] + c[2]) % d[2];
            k++;
        }
        ll sum_mn = 0, sum_mx = 0, sum = 0;
        ll mx_r = 0, mn_r = 0, mx_a = 0, mn_a = 0;
        for (ll i = 0; i < n; i++)
        {
            sum_mn += x[i];
            sum_mx += x[i] + y[i];
            sum += s[i];
            mn_r += max(zero, s[i] - (x[i] + y[i]));
            mn_a += max(zero, x[i] - s[i]);
        }
        if (sum >= sum_mn && sum <= sum_mx)
        {
            cout << "Case #" << q << ": " << max(mn_r, mn_a) << nl;
        }
        else
        {
            cout << "Case #" << q << ": " << -1 << nl;
        }
    }
    return 0;
}