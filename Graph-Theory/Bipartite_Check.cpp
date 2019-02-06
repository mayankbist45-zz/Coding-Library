
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

	int v;
	map<T,list<T>> adjList;
public:
	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	bool isBipartite(T src){
		queue<T> q;
		q.push(src);

		map<T,int> color;

		for(auto i:adjList){
			T node = i.first;
			color[node] = -1;
		}

		color[src]=0;
		bool ans = true;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			for(auto v:adjList[node]){
				if(color[v]==-1){
					color[v] = 1-color[node];
					q.push(v);
				}
				else if(color[v]==color[node]){
					return false;
				}
			}
		}
		return true;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(3, 1);
	cout<<g.isBipartite(0);

	return 0;
}
