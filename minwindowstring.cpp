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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

int main()
{
    string s = "ab", t = "b";
    int n = s.size();
    int m = t.size();
    int b[52], c[52];
    for (int i = 0; i < 52; i++)
    {
        c[i] = 0;
        b[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (t[i] > 'Z')
        {
            b[t[i] - 'a' + 26]++;
        }
        else
        {
            b[t[i] - 'A']++;
        }
    }
    int j = -1;
    int res = n + 1;
    string str = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] > 'Z')
        {
            c[s[i] - 'a' + 26]++;
        }
        else
        {
            c[s[i] - 'A']++;
        }
        bool bchk = true;
        for (int k = 0; k < 52; k++)
        {
            // var(c[k], b[k], -1);
            if (c[k] < b[k])
            {
                bchk = false;
                break;
            }
        }
        while (bchk)
        {
            if ((i - j) < res)
            {
                res = (i - j);
                str = s.substr(j + 1, i - j);
            }
            j++;
            if (s[j] > 'Z')
            {
                c[s[j] - 'a' + 26]--;
            }
            else
            {
                c[s[j] - 'A']--;
            }
            for (int k = 0; k < 52; k++)
            {
                if (c[k] < b[k])
                {
                    bchk = false;
                    break;
                }
            }
        }
    }
    cout << str << nl;
    return 0;
}