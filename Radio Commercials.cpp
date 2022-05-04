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

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int mx=0, ans=-1;
    for (int i=0; i<n; i++) {
        if (a[i]-d+mx >= 0) {
            mx += a[i]-d;
        } else {
            mx = 0;
        }
        ans = max(ans, mx);
    }

    cout << ans;

    return 0;
}
/*
4
4 5 1 3
*/
