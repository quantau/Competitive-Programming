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

    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll ct = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s.substr(i, 3) == "abc")
            ct++;
    }
    while (q--)
    {
        ll i;
        char c;
        cin >> i >> c;
        i--;
        for (ll j = i - 2; j <= i; j++)
        {
            if (j >= 0 && j + 2 < n)
            {
                if (s.substr(j, 3) == "abc")
                    ct--;
            }
        }
        s[i] = c;
        for (ll j = i - 2; j <= i; j++)
        {
            if (j >= 0 && j + 2 < n)
            {
                if (s.substr(j, 3) == "abc")
                    ct++;
            }
        }
        cout << ct << nl;
    }
    return 0;
}