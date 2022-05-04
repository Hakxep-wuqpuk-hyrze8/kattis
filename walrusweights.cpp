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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int dp[2005]={0};
    dp[0]=1;
    for (int i=0; i<n; i++) {
        for (int j=2000-a[i]; j>=0; j--) {
            if (dp[j])
                dp[j+a[i]]++;
        }
    }

    if (dp[1000]) {cout << 1000; return 0;}
    for (int i=1; i<1000; i++) {
        if (dp[1000+i]) {
            cout << 1000+i;
            return 0;
        }
        if (dp[1000-i]) {
            cout << 1000-i;
            return 0;
        }
    }

    return 0;
}

/*
*/
