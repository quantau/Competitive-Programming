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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll i = 0, j = k - 1;
        ll index = 0;
        string t = "";
        while (i <= j)
        {
            if (index % 2)
            {
                t += s[j];
                j--;
            }
            else
            {
                t += s[i];
                i++;
            }
            index++;
        }
        reverse(all(t));
        cout << t;
        for (ll i = k; i < n; i++)
        {
            cout << s[i];
        }
        cout << nl;
    }
    return 0;
}