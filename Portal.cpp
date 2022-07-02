#include <bits/stdc++.h>
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
// #define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define on_bit(x) __builtin_popcountint(x)
#define msb(x) (63 - __builtin_clzint(x))
#define lsb(x) __builtin_ctzint(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

const int inf = 1e9 + 7;

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m], b[n][m]; // a--> beech ka b-->bahar ka
        int pref[n][m];
        int pref2[n][m];
        int arr[n][m];

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                a[i][j] = inf;
                b[i][j] = inf;
                arr[i][j] = s[j] - '0';
                if (j > 0)
                {
                    pref[i][j] = pref[i][j - 1] + arr[i][j];
                }
                else
                {
                    pref[i][j] = arr[i][j];
                }
                if (i == 0)
                {
                    pref2[i][j] = arr[i][j];
                }
                else
                {
                    pref2[i][j] = pref2[i - 1][j] + arr[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                pref2[i][j] += pref2[i][j - 1];
            }
        }

        int ans = inf;
        for (int j = 3; j < m; j++)
        {
            for (int sz = 3; sz <= j; sz++)
            {
                b[0][j] = (sz - 1) - (pref[0][j - 1] - pref[0][j - sz]);
                for (int i = 1; i < n; i++)
                {
                    b[i][j] = min((sz - 1) - (pref[i][j - 1] - pref[i][j - sz]), b[i - 1][j] + pref[i][j - 1] - pref[i][j - sz] + !arr[i][j] + !arr[i][j - sz]);
                    if (i >= 4)
                    {
                        int mid = (pref2[i - 1][j - 1] - pref2[i - 4][j - 1]) - (pref2[i - 1][j - sz] - pref2[i - 4][j - sz]);
                        int left;
                        if (j - sz > 0)
                        {
                            left = 3 - ((pref2[i - 1][j - sz] - pref2[i - 4][j - sz]) - (pref2[i - 1][j - sz - 1] - pref2[i - 4][j - sz - 1]));
                        }
                        else
                        {
                            left = 3 - (pref2[i - 1][j - sz] - pref2[i - 4][j - sz]);
                        }
                        int right = 3 - ((pref2[i - 1][j] - pref2[i - 4][j]) - (pref2[i - 1][j - 1] - pref2[i - 4][j - 1]));
                        int last = ((sz - 1) - (pref[i][j - 1] - pref[i][j - sz]));
                        ans = min(ans, b[i - 4][j] + last + mid + left + right);
                    }
                }
            }
        }
        cout << ans << nl;
    }
    return 0;
}
