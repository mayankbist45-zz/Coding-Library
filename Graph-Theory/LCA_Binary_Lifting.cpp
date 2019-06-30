#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

#define maxn 10000
vector<int> g[maxn];
vector<vector<int>> up;
int tout[maxn], tin[maxn];
int timer = 0, L;

void dfs(int u, int p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (int i = 1; i <= L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (auto &x: g[u]) {
        if (x == p)continue;
        dfs(x, u);
    }
    tout[u] = ++timer;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v))
        return u;
    if (isAncestor(u, v))
        return v;
    for (int i = L; i >= 0; i--) {
        if (!isAncestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1));
    dfs(1, 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}