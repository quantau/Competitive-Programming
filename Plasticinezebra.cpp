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

    string s;
    cin >> s;
    ll n = s.size();
    ll res = 0, val = 1, in = 0;
    s += s;
    char c = s[0];
    for (ll i = 1; i < 2 * n; i++)
    {
        if (s[i] != c && i < in + n)
        {
            val++;
            c = s[i];
        }
        else
        {
            res = max(res, val);
            val = 1;
            in = i;
        }
    }
    cout << res << nl;
    return 0;
}