#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, x, y, w;
vector<int> num;
int dp[20][200][1500][2];

bool isCoprime(int a, int b) {
    return __gcd(a, b) == 1;
}

int go(int pos, int sV, int sS, int f) {
    if (pos == num.size()) {
        if (isCoprime(sV, sS)) {
            return 1;
        }
        return 0;
    }

    int &ans = dp[pos][sV][sS][f];
    if (ans != -1)
        return ans;
    ans = 0;
    int LMT;
    if (f)
        LMT = 9;
    else LMT = num[pos];

    for (int dgt = 0; dgt <= LMT; dgt++) {
        int nf = f;
        if (nf == 0 and dgt < LMT)nf = 1;
        ans += go(pos + 1, sV + dgt, sS + dgt * dgt, nf);
    }
    return ans;
}

int solve(int x) {
    num.clear();
    while (x > 0)
        num.push_back(x % 10), x /= 10;
    memset(dp, -1, sizeof dp);
    reverse(num.begin(), num.end());
    int ans = go(0, 0, 0, 0);
    return ans;
}

int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
}



