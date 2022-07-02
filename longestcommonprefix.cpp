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

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 0;
        string s = a;
        int res = 1;
        while (s.size() < b.size())
        {
            res++;
            s += a;
        }
        if (kmp(b, s))
            return res;
        s += a;
        if (kmp(b, s))
            return res + 1;
        return -1;
    }

    int kmp(string &a, string &b)
    {
        ll n = a.size();
        ll m = b.size();

        // initializng the lps array
        ll lps[n];
        lps[0] = 0;
        ll len = 0;
        ll i = 1;
        while (i < n)
        {
            if (a[i] == a[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // finding complete occurences of a in b
        i = 0;
        ll j = 0;
        ll res = 0;
        while (i < m)
        {
            if (b[i] == a[j])
            {
                i++;
                j++;
            }
            if (j == n)
            {
                res++;
                j = 0;
            }
            else if (i < m && b[i] != a[j])
            {
                if (j)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return res;
    }
};

int main()
{
    FASTIO
    string a, b;
    cin >> a >> b;
    Solution s;
    cout << s.repeatedStringMatch(a, b);
    return 0;
}