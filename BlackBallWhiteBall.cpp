#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

long long binpow(long long a, long long b, const long long MOD)
{
    a = a % MOD;
    if (a == 0)
        return 0;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res % MOD) * (a % MOD);
            res %= MOD;
        }
        a %= MOD;
        a = (a % MOD) * (a % MOD);
        a %= MOD;
        b >>= 1;
    }
    return res % MOD;
}

long long mi(long long x)
{
    return binpow(x, mod - 2, mod) % mod;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long b, w;
    cin >> b >> w;
    long long x = (2 * w + 2 * b - 1) % mod;
    long long y = (2 * w + b - 1);
    long long res = w % mod;
    res *= x;
    res %= mod;
    res *= mi(y + 1) % mod;
    res %= mod;
    res *= mi(y) % mod;
    res %= mod;
    cout << res % mod << nl;
    return 0;
}