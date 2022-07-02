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

    ll n, h, w;
    cin >> n >> w >> h;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    ll dp[n];
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > w && h[i] > h)
        {
            dp[i] = 1;
            break;
        }
        dp[i]=0;
    }
    
    return 0;
}