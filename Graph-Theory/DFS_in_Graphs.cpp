
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

	void dfs(T src){
		map<T,bool> visited;
		int component = 1;
		dfsHelper(src,visited);

		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				dfsHelper(node,visited);
				component++;
			}
		}
		cout<<"\nThe graph has total "<<component<<" components!";
	}

	void dfsHelper(T node,map<T,bool> &visited){
		visited[node] = true;
		cout<<node<<" ";

		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited);
			}
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph<int> g;
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,4);
	g.addEdge(5,6);
	g.dfs(1);

	return 0;
}
