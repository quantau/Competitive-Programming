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

    ll n, x;
    cin >> n >> x;
    ll a[n + 2];
    vector<ll> sum(n + 2, 0);
    vector<ll> mx_sum_suff(n + 2, 0);
    vector<ll> mx_sum_pref(n + 2, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sum[n + 1] = sum[n];
    for (ll i = 1; i <= n; i++)
    {
        mx_sum_pref[i] = mx_sum_pref[i - 1] + a[i];
        if (mx_sum_pref[i] < 0)
        {
            mx_sum_pref[i] = 0;
        }
    }

    for (ll i = n; i >= 1; i--)
    {
        mx_sum_suff[i] = mx_sum_suff[i + 1] + a[i];
        if (mx_sum_suff[i] < 0)
        {
            mx_sum_suff[i] = 0;
        }
    }

    vector<ll> suff(n + 2);
    suff[n + 1] = x * sum[n + 1];
    for (ll i = n; i >= 0; i--)
    {
        suff[i] = max(suff[i + 1], x * sum[i] + mx_sum_suff[i + 1]);
        // cout << suff[i] << " ";
    }
    // cout << nl;

    ll ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        ans = max(ans, suff[i + 1] + (mx_sum_pref[i] - x * sum[i]));
        // cout << ans << " ";
    }
    // cout << nl;
    cout << ans << nl;
    return 0;
}