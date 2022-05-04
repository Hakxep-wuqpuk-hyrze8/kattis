#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9+7;
const int mxN = 1e3+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s2, s1="abcdefghijklmnopqrstuvwxyz";
    cin >> s2;
    int n=s2.length();
    int dp[30][n+5];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=26; i++) {
        for (int j=1; j<=n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    cout << 26-dp[26][n];

    return 0;
}

/*
*/
