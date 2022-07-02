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

    ll a[16] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    ll res = 0;
    for (ll i = 0; i < 16; i++)
    {
        cout << a[i] << endl;
        string s;
        cin >> s;
        ll num = a[i];
        while (s == "yes")
        {
            num *= a[i];
            // dbg(1);
            res++;
            if (num > 100)break;
            cout << num << endl;
            cin >> s;
        }
        if (res > 1)
        {
            cout << "composite" << endl;
            return 0;
        }
    }
    if (res <= 1)
    {
        cout << " prime " << endl;
    }
    return 0;
}