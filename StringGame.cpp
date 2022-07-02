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

void srt(ll c[])
{
    if (c[0] > c[1])
        swap(c[0], c[1]);
}

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
        ll c[2] = {0, 0};
        for (ll i = 0; i < n; i++)
        {
            c[s[i] - '0']++;
        }
        ll loser;
        for (ll i = 0; i < n; i++)
        {
            srt(c);
            if (c[0] == 0)
            {
                loser = i;
                break;
            }
            if ((c[0] - 1) % 2)
            {
                c[1]--;
            }
            else
            {
                c[0]--;
            }
        }
        if (loser % 2)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }
    return 0;
}