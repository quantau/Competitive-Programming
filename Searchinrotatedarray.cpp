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
    const int inf = 1e9 + 7;

    int bin_Search(vector<int> &nums, int l, int r, int target, int p)
    {
        int res = inf;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if ((!p && nums[mid] >= target) || (p && nums[mid] < target))
            {
                res = min(res, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return (p || (res < inf && nums[res] == target) ? res : -1);
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int j = bin_Search(nums, 0, n - 1, nums[0], 1);
        // dbg(j);
        if (j > n)
        {
            return bin_Search(nums, 0, n - 1, target, 0);
        }
        else
        {
            int res1 = bin_Search(nums, 0, j - 1, target, 0);
            int res2 = bin_Search(nums, j, n - 1, target, 0);
            return max(res1, res2);
        }
    }
};

int main()
{
    FASTIO

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    Solution sol;
    cout << sol.search(nums, target);
    return 0;
}