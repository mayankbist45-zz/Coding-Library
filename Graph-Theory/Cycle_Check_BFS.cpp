
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

	bool isCyclicBFS(T src){
		queue<T> q;
		map<T,bool> visited;
		map<T,T> parent;

		q.push(src);
		visited[src]=true;
		parent[src]=src;

		while(!q.empty()){
			T node = q.front();
			q.pop();
			for(auto neighbour:adjList[node]){
				if(visited[neighbour]==true&&parent[node]!=neighbour){
					return true;
				}
				else if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = node;
				}
			}
		}
		return false;
	}
	
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph<int> g;
	   g.addEdge(1,2);
	   g.addEdge(2,3);
	   g.addEdge(3,1);
	   g.addEdge(4,5);
	   cout<<g.isCyclicBFS(1);

	return 0;
}
