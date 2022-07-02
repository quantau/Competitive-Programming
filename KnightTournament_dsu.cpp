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

ll p[300009];

ll get(ll x)
{
    if (p[x] == x)
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

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n + 4; i++)
    {
        p[i] = i;
    }
    while (m--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        ll curr = get(l);
        while (curr <= r)
        {
            if (curr == x)
            {
                curr++;
                // if (curr > n)
                //     break;
            }
            else
            {
                a[curr] = x;
                p[curr] = curr + 1;
            }
            curr = get(curr);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << nl;
    return 0;
}