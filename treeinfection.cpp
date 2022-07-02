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

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n + 1);
        ll z = 1;
        for (ll i = 2; i <= n; i++)
        {
            ll x;
            cin >> x;
            v[x]++;
            if (v[x] == 1)
                z++;
        }

        sort(rall(v));
        ll res = z;
        // dbg(res);
        multiset<ll> s;
        for (ll i = 0; i <= n; i++)
        {
            if (!v[i])
                break;
            if (v[i] - z > 0)
            {
                s.insert(-(v[i] - z));
            }
            // var(v[i] - z, v[i], z);
            z--;
        }

        while (!s.empty())
        {
            multiset<ll> st;
            bool b = false;
            // for (auto x : s)
            // {
            //     cout << x << " ";
            // }
            // cout << nl;
            for (auto x : s)
            {
                if (!b)
                {
                    b = true;
                    ll val = x + 2;
                    if (val < 0)
                        st.insert(val);
                    continue;
                }
                ll val = x + 1;
                if (val < 0)
                    st.insert(val);
            }
            s = st;
            res++;
        }
        cout << res << nl;
    }
    return 0;
}