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

    int n;
    while (cin >> n && n) {
        vi a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vi ans;
        int dp[n+5], l=1;
        dp[0]=1;
        ans.pb(a[0]);

        for (int i=1; i<n; i++) {
            if (ans.back() < a[i]) {
                ans.pb(a[i]);
                l++;
                dp[i] = l;
            } else {
                auto it = upper_bound(ans.begin(), ans.end(), a[i]);
                *it = a[i];
                dp[i] = (int)(it-ans.begin()+1);
            }
        }

        vi ans_t;
        cout << l << ' ';
        for (int i=n-1; i>=0; i--) {
            if (dp[i] == l) {
                ans_t.pb(a[i]);
                l--;
                if (l==0) break;
            }
        }

        reverse(ans_t.begin(), ans_t.end());
        for (auto &i : ans_t) cout << i << ' ';
        cout << '\n';
    }


    return 0;
}

/*
4 1 25 2 3
4 1 2 2 3
8 90 4 10000 2 18 60 172 99
0
*/
