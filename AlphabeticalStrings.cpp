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
        string s;
        cin >> s;
        ll i = 0, j = s.size() - 1;
        ll val = s.size();
        if (val == 1 && s[0] != 'a')
        {
            cout << "NO\n";
            continue;
        }
        while (i != j)
        {
            ll val1 = s[i] - 'a';
            ll val2 = s[j] - 'a';
            if (val1 > val2 && val1 < val)
            {
                i++;
                val = val1;
            }
            else if (val2 > val1 && val2 < val)
            {
                j--;
                val = val2;
            }
            else
            {
                break;
            }
        }
        if (i != j)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}