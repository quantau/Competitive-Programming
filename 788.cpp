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

// for prime i sieve[i]=0 else not
const ll MAXN = 1e5;
const ll mod = 1e9 + 7;
bool sieve[MAXN + 5];
vector<ll> prime;

void pre(ll n = MAXN)
{
    for (ll i = 2; i <= n; i++)
    {
        if (sieve[i])
            continue;
        prime.pb(i);
        for (ll j = i * i; j <= n; j += i)
            sieve[j] = i;
    }
}

int main()
{
    FASTIO

    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        ll b, d1, n1, c, d2, n2;
        cin >> b >> d1 >> n1 >> c >> d2 >> n2;
        ll d = d2;
        ll bl = b + d1 * (n1 - 1);
        ll cl = c + d2 * (n2 - 1);
        if (cl > bl || c < b || (c - b) % d1 || __gcd(d1, d2) != d1)
        {
            cout << 0 << nl;
            continue;
        }
        else if (cl + d2 > bl || c - d2 < b)
        {
            cout << -1 << nl;
            continue;
        }
        else
        {
            vector<ll> v;
            ll val = 1;
            for (auto x : prime)
            {
                if (x * x > d2)
                {
                    break;
                }
                ll num = 1;
                while (d2 % x == 0)
                {
                    d2 /= x;
                    num *= x;
                }
                if (d1 % num)
                {
                    val *= num;
                }
                else
                {
                    while (num > 1)
                    {
                        v.pb(x);
                        num /= x;
                    }
                }
            }
            if (d2 > 1)
            {
                if (d1 % d2)
                {
                    val *= d2;
                }
                else
                {
                    v.pb(d2);
                }
            }
            ll m = v.size();
            var("i am-> ", val, " <-this value");
            // for (auto x : v)
            // {
            //     cout << x << " ";
            // }
            // cout << nl;
            ll n = (1 << m);
            ll res = 0;
            set<ll> st;
            for (ll i = 0; i < n; i++)
            {
                ll di = val;
                for (ll j = 0; j < m; j++)
                {
                    if (i & (1 << j))
                    {
                        di *= v[j];
                    }
                }
                if (st.find(di / val) != st.end())
                    continue;
                st.insert(di / val);
                ll cont = (d / di) * (d / di);
                res += cont;
                res %= mod;
            }
            for (auto x : st)
            {
                cout << x << " ";
            }
            cout << nl;
            cout << res << nl;
        }
    }
    return 0;
}