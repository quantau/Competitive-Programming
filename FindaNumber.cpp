#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define nl "\n";
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);

using namespace std;

const ll inf = 1e15 + 7;
ll dp[5005][505];
pii par[5005][505];

ll binpow(ll a, ll b, const ll MOD)
{
    a = a % MOD;
    if (a == 0)
        return 0;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res % MOD) * (a % MOD);
            res %= MOD;
        }
        a %= MOD;
        a = (a % MOD) * (a % MOD);
        a %= MOD;
        b >>= 1;
    }
    return res % MOD;
}

int main()
{
    FASTIO

    ll d, s;
    cin >> d >> s;

    for (ll i = 0; i <= s; i++)
    {
        for (ll j = 0; j <= d; j++)
        {
            dp[i][j] = -1;
        }
    }

    dp[s][0] = 0;
    queue<pii> q;
    q.push({s, 0});
    while (!q.empty())
    {
        pii p = q.front();
        ll i = p.ff, j = p.ss;
        q.pop();
        for (ll k = 0; k < 10; k++)
        {
            if (i - k < 0)
                continue;
            ll l = (10 * j + k) % d;
            if (dp[i - k][l] == -1 || dp[i - k][l] > dp[i][j] + 1)
            {
                dp[i - k][l] = dp[i][j] + 1;
                par[i - k][l] = {i, j};
                q.push({i - k, l});
            }
        }
    }

    if (dp[0][0] == -1)
    {
        cout << -1 << nl;
        return 0;
    }
    ll len = dp[0][0];

    ll i = 0, j = 0;
    vector<ll> res;
    while (len--)
    {
        res.pb(par[i][j].ff - i);
        ll ti = par[i][j].ff;
        ll tj = par[i][j].ss;
        i = ti, j = tj;
    }
    reverse(all(res));
    for (auto x : res)
    {
        cout << x;
    }
    return 0;
}