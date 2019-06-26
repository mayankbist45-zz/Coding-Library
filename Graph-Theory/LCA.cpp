//LCA using Euler Tour
#include <bits/stdc++.h>

using namespace std;

#define maxn 10000
vector<int> g[maxn];
vector<int> euler, height, first, tree;

void build(int start, int end, int index) {
    if (start == end)
        tree[index] = euler[start];
    else {
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        int l = tree[2 * index], r = tree[2 * index + 1];
        tree[index] = (height[l] < height[r]) ? l : r;
    }
}


int query(int index, int start, int end, int q1, int q2) {
    if (start > q2 or end < q1)
        return -1;
    if (start >= q1 and end <= q2)
        return tree[index];

    int mid = (start + end) / 2;
    int left = query(2 * index, start, mid, q1, q2);
    int right = query(2 * index + 1, mid + 1, end, q1, q2);
    if (left == -1)return right;
    if (right == -1)return left;
    return height[left] < height[right] ? left : right;
}

void dfs(int u, int p = -1, int h = 1) {
    first[u] = euler.size();
    euler.push_back(u);
    height[u] = h;
    for (auto v : g[u]) {
        if (v == p)continue;
        dfs(v, u, h + 1);
        euler.push_back(u);
    }
}

int lca(int u, int v) {
//#warning We can define a segment tree for the queries to achieve O(log n)
    int left = first[u], right = first[v];
    if (left > right)
        swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    first.resize(n + 1);
    height.resize(n + 1);
    dfs(1, 0);
    tree.resize(euler.size() * 4);
    build(0, euler.size() - 1, 1);

    for (int i = 0; i < euler.size(); i++) {
        cout << euler[i] << " " << height[euler[i]] << endl;
    }

    int q;
    cin >> q;

    for (int j = 0; j < q; ++j) {
        int l, r;
        cin >> l >> r;

        cout << lca(l, r) << endl;
    }

    return 0;
}