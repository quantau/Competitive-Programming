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

    ll inf = 1e14;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> pos(k);
        vector<ll> tem(n + 1, inf);
        for (ll i = 0; i < k; i++)
        {
            ll x;
            cin >> x;
            x--;
            pos[i] = x;
        }
        for (ll i = 0; i < k; i++)
        {
            ll x;
            cin >> x;
            tem[pos[i]] = x;
        }
        vector<ll> ft(n, inf);
        vector<ll> bk(n, inf);
        ft[0] = min(ft[0], tem[0]);
        for (ll i = 1; i < n; i++)
        {
            ft[i] = min(ft[i - 1] + 1, tem[i]);
        }
        bk[n - 1] = min(bk[n - 1], tem[n - 1]);
        for (ll i = n - 2; i >= 0; i--)
        {
            bk[i] = min(bk[i + 1] + 1, tem[i]);
        }
        for (ll i = 0; i < n; i++)
        {
            cout << min(ft[i], bk[i]) << " ";
        }
        cout << nl;
    }
    return 0;
}