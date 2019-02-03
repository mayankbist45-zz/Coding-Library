
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

	void bfs(T src){
		queue<T> q;
		map<T,bool> visited;

		q.push(src);
		visited[src]=true;

		while(!q.empty()){
			T node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
				}
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
	g.addEdge(1,3);
	g.bfs(1);

	return 0;
}
