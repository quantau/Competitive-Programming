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

vector<ll> p(150001, -1);
vector<ll> v[150001];

ll get(ll x)
{
    if (p[x] < 0)
        return x;
    p[x] = get(p[x]);
    return p[x];
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        v[i].pb(i);
    }
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        x = get(x);
        y = get(y);
        if (-p[x] < -p[y])
            swap(x, y);
        for (auto z : v[y])
        {
            v[x].pb(z);
        }
        p[x] += p[y];
        p[y] = x;
    }
    ll r = get(1);
    for (auto z : v[r])
    {
        cout << z << " ";
    }
    cout << nl;
    return 0;
}