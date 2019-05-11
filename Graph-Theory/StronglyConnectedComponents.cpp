
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g, g1;
vector<bool> visited;
vector<int> component, order;

void dfs1(int v) {
    visited[v] = true;
    for (auto x:g[v])
        if(!visited[x])
            dfs1(x);
    order.push_back(v);
}

void dfs2(int v){
    visited[v] = true;
    component.push_back(v);
    for(auto x: g1[v])
        if(!visited[x])
            dfs2(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    int a,b;
    g.assign(n+1,vector<int>());
    g1.assign(n+1,vector<int>());

    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g1[b].push_back(a);
    }

    visited.assign(n,false);
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs1(i);
    visited.assign(n,false);
    for(int i=0;i<n;i++){
        int v = order[n-i-1];
        if(!visited[v]){
            dfs2(v);
            for(auto x:component)
                cout<<x+1<<" ";
            cout<<endl;
            component.clear();
        }
    }

    return 0;
}