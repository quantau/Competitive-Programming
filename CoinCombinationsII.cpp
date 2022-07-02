#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int dp[MAXN];

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - a[i] >= 0)
            {
                dp[j] += dp[j - a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] % MOD << "\n";
    return 0;
}