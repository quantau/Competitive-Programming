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

    ll l, r;
    cin >> l >> r;
    string s;
    cin >> s;
    string t = s.substr(l - 1, (r - l + 1));
    reverse(all(t));
    for (ll i = 0; i < l - 1; i++)
    {
        cout << s[i];
    }
    cout << t;
    for (ll i = r; i < s.size(); i++)
    {
        cout << s[i];
    }
    return 0;
}