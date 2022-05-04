#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 2e3+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, total;
    while (cin >> total >> n) {
        vi w(n), v(n);
        vector<vector<ll>> dp(n+5, vector<ll>(mxN, 0));

        for (int i=0; i<n; i++) {
            cin >> v[i] >> w[i];
        }

        for (int i=0; i<n; i++) {
            for (int j=total; j>=0; j--) {
                if (j>=w[i])
                    dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
                else
                    dp[i+1][j] = dp[i][j];
            }
        }

        //cout << dp[n][total] << "\n";

        vi ans;
        for (int i=n, j=total; i>0; i--) {
            if (dp[i][j] == 0) break;
            if (dp[i][j] == dp[i-1][j]) continue;
            j-=w[i-1];
            ans.pb(i-1);
        }

        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto i : ans) cout << i << ' ';
        cout << "\n";

        ans.clear();
        v.clear();
        w.clear();
    }

    return 0;
}

/*
4 14
2 1
7 1
8 1
12 2
*/
