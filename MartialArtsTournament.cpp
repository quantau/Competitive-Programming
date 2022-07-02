#include <bits/stdc++.h>
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
        ll n;
        cin >> n;
        vector<ll> v(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            v[a]++;
        }
        ll res = 2 * n;
        for (ll i = 0; i <= 18; i++)
        {
            ll l = (1LL << i);
            for (ll j = 0; j <= 18; j++)
            {
                ll mid = (1LL << j);
                // var(l, mid, -1);
                ll ls = 0, mds = 0, ends = 0;
                ll ans = 0;
                bool b1 = true, b2 = true;
                for (ll k = 1; k <= n; k++)
                {
                    if (b1 && ls + v[k] <= l)
                    {
                        ls += v[k];
                        continue;
                    }
                    else if (b1)
                    {
                        b1 = false;
                        ans += l - ls;
                    }
                    if (b2 && mds + v[k] <= mid)
                    {
                        mds += v[k];
                        continue;
                    }
                    else if (b2)
                    {
                        b2 = false;
                        ans += mid - mds;
                    }
                    ends += v[k];
                }
                ll num = 1;
                while (ends > num)
                {
                    num *= 2;
                }
                ans += (num - ends);
                if (b1)
                {
                    ans += l - ls;
                }
                if (b2)
                {
                    ans += mid - mds;
                }
                res = min(ans, res);
            }
        }
        cout << res << nl;
    }
    return 0;
}