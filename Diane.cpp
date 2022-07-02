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
        if (n <= 26)
        {
            for (ll i = 0; i < n; i++)
            {
                char c = 'a' + i;
                cout << c;
            }
            cout << nl;
            continue;
        }
        else
        {
            for (ll i = 1; i <= n / 2; i++)
            {
                cout << 'a';
            }
            cout << 'b';
            for (ll i = 1; i < n / 2; i++)
            {
                cout << 'a';
            }
        }
        if (n % 2)
            cout << 'z';
        cout << nl;
    }
    return 0;
}