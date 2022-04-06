    for (ll j = 1; j <= g; j++)
    {
        for (ll i = 1; i <= m; i++)
        {
            // dbg(i);
            for (ll l = 1; l <= k; l++)
            {
                cout << dp[i][j][l] << " ";
            }
            cout << nl;
        }
        cout << nl;
    }