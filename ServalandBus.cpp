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

    ll n, t;
    cin >> n >> t;
    ll res = INT_MAX;
    ll ans;
    for (ll i = 0; i < n; i++)
    {
        ll s, d;
        cin >> s >> d;
        if (s >= t && s < res)
        {
            ans = i + 1;
            res = min(res, s);
        }
        else if (s < t)
        {
            ll val = ((t - s) + (d - 1)) / d;
            if (s + val * d < res)
            {
                res = s + val * d;
                ans = i + 1;
            }
        }
    }
    cout << ans << nl;
    cout << "i dobt wanna do this anymore yet i have to, wtf!!\n";
    cout<<"HERE COME MATES!\n";
    return 0;
}