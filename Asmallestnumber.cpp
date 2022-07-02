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

bool solve(ll n, ll i, ll sum, ll p, vector<ll> &v)
{
    if (i > n)
        return p >= sum;
    for (ll j = 1; j <= 9; j++)
    {
        v.pb(j);
        sum += j;
        p *= j;
        if (solve(n, i + 1, sum, p, v))
        {
            return true;
        }
        sum -= j;
        p /= j;
        v.pop_back();
    }
    return false;
}

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
        vector<ll> v;
        ll k;
        cin >> k;
        if (k < 6)
        {
            solve(k, 1, 0, 1, v);
        }
        else
        {
            for (ll i = 1; i <= k - 6; i++)
            {
                cout << 1;
            }

            solve(6, 1, k - 6, 1, v);
        }
        for (ll i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << nl;
    }
    return 0;
}