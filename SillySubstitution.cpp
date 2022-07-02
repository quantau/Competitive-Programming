#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MAXN = 5 * 1e5 + 5;
ll pre[MAXN], aft[MAXN], val[MAXN];
ll n;

ll get_f(ll x)
{
    if (aft[x] < n && val[aft[x]] == -1)
    {
        aft[x] = get_f(aft[x]);
    }
    return aft[x];
}

ll get_b(ll x)
{
    if (pre[x] >= 0 && val[pre[x]] == -1)
    {
        pre[x] = get_b(pre[x]);
    }
    return pre[x];
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("test_set_1_ts1_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for (ll q = 1; q <= t; q++)
    {
        cin >> n;
        string c;
        cin >> c;
        for (ll i = 0; i < n; i++)
        {
            pre[i] = i - 1;
            aft[i] = i + 1;
            val[i] = c[i] - '0';
        }
        set<ll> st[10];
        for (ll i = 1; i < n; i++)
        {
            if (val[i] == (val[i - 1] + 1) % 10)
            {
                st[val[i - 1]].insert(i - 1);
            }
        }
        while (1)
        {
            bool b = false;
            for (ll i = 0; i < 10; i++)
            {
                while (!st[i].empty())
                {
                    ll x = *st[i].begin();
                    st[i].erase(st[i].begin());
                    if (val[x] != -1 && val[get_f(x)] != -1 && (get_f(x) != n && val[get_f(x)] == (val[x] + 1) % 10))
                    {
                        b = true;
                        val[x] = (i + 2) % 10;
                        val[get_f(x)] = -1;
                        if (get_b(x) != -1 && val[x] == (val[get_b(x)] + 1) % 10)
                        {
                            st[val[get_b(x)]].insert(get_b(x));
                        }
                        else if (get_f(x) != n && val[get_f(x)] == (val[x] + 1) % 10)
                        {
                            st[val[x]].insert(x);
                        }
                    }
                }
            }
            if (!b)
                break;
        }
        cout << "Case #" << q << ": ";
        for (ll i = 0; i < n; i++)
        {
            if (val[i] != -1)
                cout << val[i];
        }
        cout << nl;
    }
    return 0;
}