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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll loc = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                loc = i;
                break;
            }
        }
        if (loc == -1)
        {
            cout << 1 << " " << n - 1 << " " << 2 << " " << n << nl;
        }
        else if (loc < n / 2)
        {
            cout << loc + 2 << " " << n << " " << loc + 1 << " " << n << nl;
        }
        else
        {
            cout << 1 << " " << loc + 1 << " " << 1 << " " << loc << nl;
        }
    }
    return 0;
}