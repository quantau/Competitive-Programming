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

bool solve(string s, char c1, char c2, ll n)
{
    bool b = false;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == c1 && s[i - 1] == c2)
        {
            b = true;
            s[i] = 'X';
            s[i - 1] = 'X';
            break;
        }
    }
    bool b1 = false;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == c2 && s[i - 1] == c1)
        {
            b1 = true;
            break;
        }
    }
    return (b1 && b);
}

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
    if (solve(s, 'A', 'B', n) || solve(s, 'B', 'A', n))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}