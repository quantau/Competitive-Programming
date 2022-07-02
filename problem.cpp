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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

map<ll, ll> mp;

bool pres(ll x, ll num)
{
    while (num)
    {
        ll dig = num % 10;
        if (x == dig)
            return true;
        num /= 10;
    }
    return false;
}

ll digs(ll num)
{
    ll res = 0;
    while (num)
    {
        num /= 10;
        res++;
    }
    return res;
}

int main()
{
    FASTIO

    ll n, x;
    cin >> n >> x;
    mp[x] = 0;
    queue<ll> q;
    q.push(x);
    ll ans = 101;
    while (!q.empty())
    {
        ll val = q.front();
        if (digs(val) == n)
        {
            ans = mp[val];
            break;
        }
        q.pop();
        for (ll i = 2; i < 10; i++)
        {
            if (pres(i, val) && !mp.count(i * val))
            {
                mp[i * val] = mp[val] + 1;
                q.push(i * val);
            }
        }
    }
    cout << (ans == 101 ? -1 : ans) << nl;
    return 0;
}