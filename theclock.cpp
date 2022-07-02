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

bool isPal(ll num)
{
    string str = to_string(num);
    reverse(all(str));
    while (str.size() != 4)
    {
        str += '0';
    }
    if (str[0] != str[3])
        return false;
    if (str[1] != str[2])
        return false;
    return true;
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll x;
        cin >> x;
        ll ah = x / 60;
        ll am = x % 60;
        ll hr, mn;
        hr = (s[0] - '0') * 10 + (s[1] - '0');
        mn = (s[3] - '0') * 10 + (s[4] - '0');
        set<ll> st;
        ll num = mn + hr * 100;
        ll res = 0;
        while (st.find(num) == st.end())
        {
            // var(hr, mn, -1);
            st.insert(num);
            res += isPal(num);
            mn += am;
            hr += ah + (mn / 60);
            hr %= 24;
            mn %= 60;
            num = mn + hr * 100;
        }
        cout << res << nl;
    }
    return 0;
}