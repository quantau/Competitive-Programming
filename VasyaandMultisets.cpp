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

    ll n;
    cin >> n;
    ll a[n];
    vector<ll> occ(101, 0);
    ll loc[101];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        occ[a[i]]++;
        loc[a[i]] = i;
    }
    vector<char> c(n, 'x');
    vector<ll> single;
    ll ormore = -1;
    for (ll i = 1; i <= 100; i++)
    {
        // cout << occ[i] << " "
        //    << " ";
        if (occ[i] == 1)
            single.pb(i);
        else if (occ[i] > 2)
            ormore = i;
    }
    // cout << nl;
    ll sz = single.size();
    // for (ll i = 0; i < sz; i++)
    // {
    //     cout << single[i] << " ";
    // }
    // cout << nl;
    //for (ll i = 0; i < n; i++)
    // {
    //     cout << loc[a[i]] << " ";
    // }
    // cout << nl;
    ll num = (sz - 1) / 2;
    if (sz && sz % 2)
    {
        if (ormore == -1)
        {
            cout << "NO\n";
            return 0;
        }
        else
        {
            c[loc[ormore]] = 'B';
            for (ll i = 0; i < (sz - 1) / 2; i++)
            {
                c[loc[single[i]]] = 'B';
            }
        }
    }
    else if (sz)
    {
        for (ll i = 0; i < (sz - 1) / 2; i++)
        {
            // dbg(a[loc[single[i]]]);
            c[loc[single[i]]] = 'B';
        }
        // dbg(a[loc[single[(sz - 1) / 2]]]);
        c[loc[single[(sz - 1) / 2]]] = 'B';
        num++;
    }
    for (ll i = num; i < sz; i++)
    {
        c[loc[single[i]]] = 'A';
        //dbg(a[loc[single[i]]]);
    }
    for (ll i = 0; i < n; i++)
    {
        if (c[i] == 'x')
            c[i] = 'A';
    }
    cout << "YES\n";
    for (ll i = 0; i < n; i++)
    {
        cout << c[i];
    }
    cout << nl;
    return 0;
}