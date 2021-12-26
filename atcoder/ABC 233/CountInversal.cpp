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

ll findSubarraySum(ll arr[], ll n, ll sum)
{
    map<ll, ll> prevSum;
    ll res = 0;
    ll currsum = 0;
    for (ll i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum == sum)
            res++;
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
        prevSum[currsum]++;
    }

    return res;
}

int main()
{
    ll n, sum;
    cin >> n >> sum;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findSubarraySum(arr, n, sum);
    return 0;
}