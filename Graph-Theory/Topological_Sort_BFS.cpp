
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

	void topologicalSortBFS(){
		queue<T> q;
		map<T,int> indegree;

		
		for(auto i:adjList){
			T node = i.first;
			indegree[node] = 0;
		}

		//Init the indegree of nodes
		for(auto i:adjList){
			T u = i.first;
			for(T v:adjList[u]){
				indegree[v]++;
			}
		}
		//Find out the indegree of node with 0
		for(auto i:adjList){
			T node = i.first;
			if(indegree[node]==0){
				q.push(node);
			}
		}

		//Start with th algorithm
		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<"->";
			for(T neighbour:adjList[node]){
				indegree[neighbour]--;
				if(indegree[neighbour]==0){
					q.push(neighbour);
				}
			}
		}
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
	g.topologicalSortBFS();

	return 0;
}
