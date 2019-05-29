
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<bool> visited;
int timer;
set<int> st;
vector<int> dfsTime, low;

void dfs(int v, int p) {
    visited[v] = true;
    int children = 0;
    dfsTime[v] = low[v] = timer++;
    for (auto to:g[v]) {
        if (to == p)
            continue;
        if (visited[to])
            low[v] = min(low[v], dfsTime[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= dfsTime[v] && p != -1)
                st.insert(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        st.insert(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int a, b;
    g.assign(n + 1, vector<int>());
    dfsTime.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    visited.assign(n, false);
    dfs(0, -1);

    cout << st.size() << endl;
    return 0;
}