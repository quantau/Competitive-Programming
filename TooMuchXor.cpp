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
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1)
        {
            cout << 0 << nl;
            continue;
        }
        else if (n == 2)
        {
            if (a[0] != a[1])
            {
                cout << 0 << nl;
            }
            else
            {
                cout << -1 << nl;
            }
            continue;
        }
        else if (n == 3)
        {
            if (a[0] != 0 || a[1] != 0 || a[2] != 0)
            {
                if (a[0] == a[2])
                {
                    if (a[0] == 0)
                    {
                        cout << 0 << nl;
                    }
                    else
                    {
                        cout << 1 << nl;
                        cout << 1 << " " << 3 << " " << 2 << nl;
                    }
                }
                else if (a[1] == 0)
                {
                    if (a[0] == 0)
                    {
                        cout << 1 << nl;
                        cout << 3 << " " << 2 << " " << 1 << nl;
                    }
                    else if (a[2] == 0)
                    {
                        cout << 1 << nl;
                        cout << 1 << " " << 2 << " " << 3 << nl;
                    }
                    else
                    {
                        cout << 1 << nl;
                        cout << 1 << " " << 2 << " " << 3 << nl;
                    }
                }
                else
                {
                    cout << -1 << nl;
                }
            }
            else
            {
                cout << -1 << nl;
            }
            continue;
        }
        ll v1 = -1, v2 = -1;
        for (ll i = 0; i < n; i++)
        {
            if (a[i])
            {
                v1 = i;
                break;
            }
        }
        if (v1 == -1)
        {
            cout << -1 << nl;
            continue;
        }
        if (v1 + 2 < n)
        {
            v2 = v1 + 2;
        }
        else
        {
            v2 = v1 - 2;
        }
        if (a[v1] != a[v2])
        {

            ll num = !(v1 % 2);
            cout << n << nl;
            for (ll i = num; i < n; i += 2)
            {
                a[i] = a[v1] ^ a[v2];
                cout << v1 + 1 << " " << v2 + 1 << " " << i + 1 << nl;
            }
            for (ll i = !num; i < n; i += 2)
            {
                a[i] = a[num] ^ a[num + 2];
                cout << num + 1 << " " << num + 3 << " " << i + 1 << nl;
            }
            // for (ll i = 0; i < n; i++)
            //     cout << a[i] << " ";
            // cout << nl;
        }
        else
        {
            ll num = !(v1 % 2);
            cout << n - 1 << nl;
            for (ll i = num; i < n; i += 2)
            {
                a[i] = a[v1] ^ a[v2];
                cout << v1 + 1 << " " << v2 + 1 << " " << i + 1 << nl;
            }
            for (ll i = !num; i < n; i += 2)
            {
                if (i == v1)
                    continue;
                a[i] = a[v1] ^ a[num];
                cout << v1 + 1 << " " << num + 1 << " " << i + 1 << nl;
            }
            // for (ll i = 0; i < n; i++)
            //     cout << a[i] << " ";
            // cout << nl;
        }
    }
    return 0;
}