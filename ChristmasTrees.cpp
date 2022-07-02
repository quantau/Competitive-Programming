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

ll dx[2] = {-1, 1};

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
    set<ll> s;
    queue<pii> q;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
        q.push({a, 0});
    }
    ll res = 0;
    vector<ll> r;
    while (m > 0)
    {
        ll scr = q.front().ff;
        ll dis = q.front().ss;
        q.pop();
        for (ll i = 0; i < 2; i++)
        {
            if (s.find(scr + dx[i]) != s.end())
                continue;
            res += dis + 1;
            r.pb(scr + dx[i]);
            s.insert(scr + dx[i]);
            q.push({scr + dx[i], dis + 1});
            m--;
            if (m <= 0)
                break;
        }
    }
    cout << res << nl;
    for (auto x : r)
    {
        cout << x << " ";
    }
    cout << nl;
    return 0;
}