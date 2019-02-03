
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{

	int v;
	map<T,list<T>> adjList;
public:
	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(!bidir)
			adjList[v].push_back(u);
	}

	void dfsTopologicalSort(){
		map<T,bool> visited;
		list<T> ordering;

		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				dfs(node,visited,ordering);
			}
		}

		for(auto i:ordering){
			cout<<i<<"->";
		}
	}

	void dfs(T node,map<T,bool> &visited,list<T> &ordering){
		visited[node] = true;

		for(auto i:adjList[node]){
			if(!visited[i])
				dfs(i,visited,ordering);
		}
		ordering.push_front(node);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph<int> g;
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.dfsTopologicalSort();
	return 0;
}
