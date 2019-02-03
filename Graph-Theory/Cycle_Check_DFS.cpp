
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

	bool isCyclicHelper(T node,map<T,bool> &visited,T parent){
		visited[node] = true;
		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				bool isCyclic = isCyclicHelper(neighbour,visited,node);
				if(isCyclic)return true;
			}
			else
				if(neighbour!=parent)
					return true;
		}
		return false;

	}

	bool isCyclicDFS(T src){
		map <T,bool> visited;

		//Calling for finding cycles
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				bool ans = isCyclicHelper(node,visited,node);
				if(ans)return true;
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
    cout<<g.isCyclicDFS(1);


	return 0;
}
	
