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

int minimumDifference(string s, vector<string> list)
{
    // code here
    int n = list.size();
    int m = s.size();
    int c[m][26];
    for (int i = 0; i < 26; i++)
    {
        c[0][i] = 0;
    }
    c[0][s[0] - 'a'] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            c[i][j] = c[i - 1][j];
        }
        c[i][s[i] - 'a']++;
    }

    int ans = m + n;
    for (int l = 0; l < n; l++)
    {
        int k = list[l].size();
        string str = list[l];
        int freq[26] = {0};
        for (auto x : str)
        {
            freq[x - 'a']++;
        }

        int val = 0;
        for (int j = 0; j < 26; j++)
        {
            val += min(c[k - 1][j], freq[j]);
        }
        ans = min(ans, k - val);

        for (int i = k; i < m; i++)
        {
            val = 0;
            for (int j = 0; j < 26; j++)
            {
                val += min((c[i][j] - c[i - k][j]), freq[j]);
            }
            ans = min(ans, k - val);
        }
    }
    return ans;
}

int main()
{
    // FREOPEN
    FASTIO

    int n;
    cin >> n;
    vector<string> list;
    string s;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        list.pb(str);
    }
    cin >> s;
    cout << minimumDifference(s, list);

    return 0;
}