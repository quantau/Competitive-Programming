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
    reverse(all(s));
    string ans = "";
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += s[i] - '0';
    }
    ll val = sum;
    for (ll i = 0; i < n; i++)
    {
        ans += val % 10 + '0';
        sum -= (s[i] - '0');
        val = (val / 10 + sum);
    }
    if (val)
    {
        ans += val % 10 + '0';
    }
    reverse(all(ans));
    cout << ans << nl;
    return 0;
}