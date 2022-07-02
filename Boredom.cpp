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
const int MAXN = 1e5;
ll freq[MAXN];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    ll a[n];
    ll mx = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        mx = max(mx, a[i]);
    }
    ll dp[2][mx + 1]; //0--> selected 1--> not selected
    dp[0][1] = freq[1];
    dp[1][1] = 0;
    for (ll i = 2; i <= mx; i++)
    {
        dp[0][i] = dp[1][i - 1] + i * freq[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    cout << max(dp[0][mx], dp[1][mx]) << nl;
    return 0;
}