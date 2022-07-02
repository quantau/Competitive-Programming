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
        ll n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        if (rd >= rb && cd >= cb)
        {
            cout << min(rd - rb, cd - cb) << nl;
        }
        else if (rd >= rb && cd <= cb)
        {
            cout << min(rd - rb, 2 * (m - cb) + (cb - cd)) << nl;
        }
        else if (rd <= rb && cd >= cb)
        {
            cout << min(cd - cb, 2 * (n - rb) + (rb - rd)) << nl;
        }
        else
        {
            cout << min(2 * (n - rb) + (rb - rd), 2 * (m - cb) + (cb - cd)) << nl;
        }
    }
    return 0;
}