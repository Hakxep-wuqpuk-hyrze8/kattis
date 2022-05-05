#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long

const int mod = 1e9+7;
const int mxN = 1e6+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi dp1(mxN+5, 2e9), a1(n);
    for (int i=0; i<n; i++) cin >> a1[i];
    int m; cin >> m;
    vi dp2(mxN+5, 2e9), a2(m);
    for (int i=0; i<m; i++) cin >> a2[i];

    dp1[0]=0; dp2[0]=0;
    for (int i=0; i<n; i++) {
        for (int j=mxN-1; j>=0; j--) {
            if (dp1[j]!=2e9) dp1[j+a1[i]]=min(dp1[j]+1, dp1[j+a1[i]]);
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=mxN-1; j>=0; j--) {
            if (dp2[j]!=2e9) dp2[j+a2[i]]=min(dp2[j]+1, dp2[j+a2[i]]);
        }
    }

    int mn = 2e9;
    for (int i=1; i<mxN; i++) {
        if (dp1[i]!=2e9 && dp2[i]!=2e9) {
            mn = min(mn, dp1[i] + dp2[i]);
        }
    }

    if (mn == 2e9)
        cout << "impossible";
    else
        cout << mn;

    return 0;
}

/*
1 3
3 1 1 1
*/
