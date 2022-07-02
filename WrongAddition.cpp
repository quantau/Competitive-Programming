#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << nl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    ll j = 0;
    string ans = "";
    for (ll i = 0; i < s.size(); i++)
    {
        if (t[j] < s[i])
        {
            ans += '0' + (t[j] - s[i] + 10);
            if (j > t.size() || t[j + 1] != '1')
            {
                // dbg(t[j + 1]);
                // var(j, i, 0);
                cout << -1 << nl;
                return;
            }
            j += 2;
        }
        else
        {
            ans += '0' + (t[j] - s[i]);
            if (j > t.size())
            {
                cout << -1 << nl;
                return;
            }
            j++;
        }
    }
    while (j < t.size())
    {
        ans += t[j];
        j++;
    }
    while (ans.back() == '0')
    {
        ans.pop_back();
    }
    reverse(all(ans));
    cout << ans << nl;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        // dbg(t);
        solve();
    }
    return 0;
}