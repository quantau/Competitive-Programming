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

    ll n, m;
    cin >> m >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cout << 1 << endl;
        ll ans;
        cin >> ans;
        if (ans == 0)
        {
            cout << 1 << endl;
            return 0;
        }
        if (ans == -1)
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
    }
    ll lo = 1, hi = m;
    ll q = 0;
    while (lo < hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        cout << mid << endl;
        ll ans;
        cin >> ans;
        if (ans == 0)
        {
            cout << mid << endl;
            return 0;
        }
        else if ((ans == -1 && a[q]) || (ans == 1 && !a[q]))
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid;
        }
        q++;
        q = q % n;
    }
    return 0;
}