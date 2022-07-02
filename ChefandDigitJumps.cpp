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

    ll inf = 1e9 + 7;
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> v[10];
    ll d[n];
    for (ll i = 0; i < n; i++)
    {
        v[s[i] - '0'].pb(i);
        d[i] = inf;
    }
    queue<pii> q;
    q.push({0, 0});
    d[0] = 0;
    while (!q.empty())
    {
        ll ind = -(q.front()).ss;
        if (ind == n - 1)
            break;
        ll dis = (q.front()).ff;
        q.pop();
        if (dis != d[ind])
            continue;
        if (ind < n - 1 && d[ind + 1] > dis + 1 && dis + 1 <= n - 1)
        {
            d[ind + 1] = dis + 1;
            q.push({dis + 1, -(ind + 1)});
        }
        if (ind > 0 && d[ind - 1] > dis + 1 && dis + 1 <= n - 1)
        {
            d[ind - 1] = dis + 1;
            q.push({dis + 1, -(ind - 1)});
        }
        for (auto x : v[s[ind] - '0'])
        {
            if (d[x] > dis + 1 && dis + 1 <= n - 1)
            {
                d[x] = dis + 1;
                q.push({d[x], -x});
            }
        }
    }
    cout << d[n - 1] << nl;
    return 0;
}