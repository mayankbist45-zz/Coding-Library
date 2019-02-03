
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

	void prinIt(){
		for(auto i:adjList){
			cout<<i.first<<"->";
			for(auto x:i.second){
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	   Graph<int> g;
	   g.addEdge(1,2);
	   g.addEdge(2,3);
	   g.addEdge(3,4);
	   g.addEdge(4,5);
	   g.prinIt();

	return 0;
}
