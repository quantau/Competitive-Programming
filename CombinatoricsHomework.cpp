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
    ll zero = 0;
    cin >> t;
    while (t--)
    {
        ll a[3], m;
        cin >> a[0] >> a[1] >> a[2] >> m;
        sort(a, a + 3);
        ll mx = a[0] + a[1] + a[2] - 3;
        ll mn = max(a[2] - a[1] - a[0] - 1, zero);
        if (m > mx || m < mn)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}