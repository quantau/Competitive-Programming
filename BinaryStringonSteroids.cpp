#include <bits/stdc++.h>
#define sz(x) x.size()
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second

using namespace std;

void merge(int arr[], int strt, int mid, int end)
{
    int n1 = mid - strt + 1;
    int n2 = end - mid;
    int b[n1], c[n2];
    for (int i = 0; i < n1; i++)
    {
        b[i] = arr[i + strt];
    }
    for (int i = 0; i < n2; i++)
    {
        c[i] = arr[i + mid + 1];
    }
    int j = 0;
    int ind = strt;
    for (int i = 0; i < n1; i++)
    {
        while (j < n2 && c[j] <= b[i])
        {
            arr[ind] = c[j];
            j++;
            ind++;
        }
        arr[ind] = b[i];
        ind++;
    }
    while (j < n2)
    {
        arr[ind] = c[j];
        ind++;
        j++;
    }
}

void mergesort(int arr[], int strt, int end)
{
    if (strt < end)
    {
        int mid = (strt + end) / 2;
        mergesort(arr, strt, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, strt, mid, end);
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << nl;
    return 0;
}