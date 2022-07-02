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

bool solve(ll n, string &s)
{
    if (n % 2)
        return false;
    ll q = 0, f = 0, b = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '?')
            q++;
        else if (s[i] == '(')
            f++;
        else if (s[i] == ')')
            b++;
    }
    if (f > n / 2 || b > n / 2)
        return false;
    ll val = n / 2 - f;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == '?' && val)
        {
            s[i] = '(';
            cnt++;
            val--;
        }
        else
        {
            s[i] = ')';
            cnt--;
        }
        if (i != n - 1 && cnt <= 0)
            return false;
    }
    if (!cnt)
        return true;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (solve(n, s))
    {
        cout << s << nl;
    }
    else
    {
        cout << ":(\n";
    }
    return 0;
}