#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

vector<pair<pair<string, int>, pair<int, int>>> shops; // shopname,capacity,opentime,closetime
vector<vector<string>> interestedShopList;             // index of customer will be mapped to all the shops the person is interested in
vector<vector<int>> preftimeList;                      // index of customer will be mapped to 3 integers which will represent hour of the day customer is interested in

map<string, vector<int>> mp; // will map shop to max empty space in store

// it is our assumption that if a customer is interest in visiting an array of shops at time x then he will get over with his work in 1 hr regardless
// of the quantity of shops in his list
int main()
{

    // input of shop data
    int n; // number of shops
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int cap, opentime, closetime;
        cin >> s >> cap >> opentime >> closetime;
        shops.pb({{s, cap}, {opentime, closetime}});
    }

    // input of customer data
    int q; // number of queries
    for (int i = 0; i < q; i++)
    {
        // i will be considered as the index of customer
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        vector<int> preftime = {t1, t2, t3};
        int m; // length of list of shops interested by customer
        cin >> m;
        vector<string> vec(m);
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            vec[i] = s;
        }
        interestedShopList.pb(vec);
        preftimeList.pb(preftime);
    }

    // mapping shop name to array of size 24 where the ith index of array represents the number of people that can visit the shop at the ith hour of the day
    for (auto x : shops)
    {
        string shop_name = x.ff.ff;
        int cap = x.ff.ss;
        int opentime = x.ss.ff;
        int closetime = x.ss.ss;

        // initializing the map
        for (int j = 0; j < 24; j++)
        {
            mp[shop_name].pb(0);
        }

        // inserting data in map
        if (closetime >= opentime)
        {
            for (int j = opentime; j <= closetime; j++)
            {
                mp[shop_name][j] = cap;
            }
        }
        else
        {
            for (int j = 0; j <= closetime; j++)
            {
                mp[shop_name][j] = cap;
            }
            for (int j = opentime; j < 24; j++)
            {
                mp[shop_name][j] = cap;
            }
        }
    }

    // algorithm
    int res[q];
    for (int i = 0; i < q; i++)
    {
        int mn_dis = 24, time = -1;
        int t1 = preftimeList[i][0];
        int t2 = preftimeList[i][1];
        int t3 = preftimeList[i][2];
        int total_Shops_interest = interestedShopList[i].size();
        vector<int> vec(24, 0);
        for (auto x : interestedShopList[i])
        {
            for (auto z : mp[x])
            {
                if (z > 0)
                {
                    vec[z]++;
                }
            }
        }

        for (int i = 0; i < 24; i++)
        {
            if (vec[i] >= total_Shops_interest)
            {
                ll dis = min({abs(t1 - i), abs(t2 - i), abs(t3 - i)});
                if (dis < mn_dis)
                {
                    mn_dis = dis;
                    time = i;
                }
            }
        }

        //updating the new capacity of shops
        if (time != -1)
        {
            for (auto x : interestedShopList[i])
            {
                mp[x][time]--;
            }
        }
        res[i] = time;
    }

    for (int i = 0; i < q; i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}