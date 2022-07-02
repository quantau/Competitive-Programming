#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int a[], int l, int r)
    {
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (a[j] <= a[r - 1])
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        return i;
    }

    int randomPartiiton(int a[], int l, int r)
    {
        srand(time(0));
        int f = l + rand() % (r - l + 1);
        swap(a[r], a[f]);
        int j = partition(a, l, r + 1);
        return j;
    }

    int kthSmallest(int a[], int l, int r, int k)
    {
        if (l == r)
            return a[l];
        int j = randomPartiiton(a, l, r);
        if (k == j - l + 1)
            return a[j];
        else if (k < j - l + 1)
        {
            return kthSmallest(a, l, j - 1, k);
        }
        else
        {
            return kthSmallest(a, j + 1, r, k - (j - l + 1));
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    Solution Sol;
    cout << Sol.kthSmallest(a, 0, n - 1, k) << endl;
    return 0;
}