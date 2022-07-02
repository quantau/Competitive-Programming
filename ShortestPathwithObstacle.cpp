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
        ll xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        ll res = 0;
        if (xa == xb && xb == xc && max(ya, yb) > yc && min(ya, yb) < yc)
        {
            res += 2;
        }
        else if (ya == yb && yb == yc && max(xa, xb) > xc && min(xa, xb) < xc)
        {
            res += 2;
        }
        cout << abs(xa - xb) + abs(ya - yb) + res << nl;
    }
    return 0;
}