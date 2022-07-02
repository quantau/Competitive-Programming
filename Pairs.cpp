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

ll n, m;
vector<bool> vec(300001, 0);
vector<pii> v;

void check(ll num)
{
    for (ll i = 0; i < m; i++)
    {
        if (!vec[i])
        {
            if (v[i].ff != num && v[i].ss != num)
                continue;
            vec[i] = true;
        }
    }
}

bool solve(ll val)
{
    check(val);
    for (ll i = 0; i < m; i++)
    {
        if (!vec[i])
        {
            check(v[i].ff);
            for (ll j = 0; j < m; j++)
            {
                if (!vec[j])
                {
                    for (ll l = 0; l < m; l++)
                    {
                        vec[l] = false;
                        if (v[l].ff == val || v[l].ss == val)
                        {
                            vec[l] = true;
                        }
                    }
                    check(v[i].ss);
                    for (ll l = 0; l < m; l++)
                    {
                        if (!vec[l])
                            return false;
                    }
                    break;
                }
            }
            break;
        }
    }
    return true;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    if (solve(v[0].ff))
    {
        cout << "YES\n";
        return 0;
    }
    for (ll i = 0; i < m; i++)
    {
        vec[i] = false;
    }
    if (solve(v[0].ss))
    {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";

    return 0;
}