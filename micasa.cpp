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
        ll n, m;
        cin >> n >> m;
        m++;
        ll num = 1 << 30;
        //cout << num;
        ll res = 0;
        while (num > 0)
        {
            if (!(n & num) && (m & num))
            {
                res += num;
            }
            else if ((n & num) && !(m & num))
            {
                break;
            }
            num /= 2;
            //var(res, (n & num), ((m & num)));
            //num >> 1;

            //dbg(num);
        }
        cout << res << nl;
    }
    return 0;
}