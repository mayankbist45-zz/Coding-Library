
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

struct edge{
	int u,v,w;
};
int n,m,dest;
vector<edge> e;
void ford(){

	vector<int> d(n,MOD);
	vector<int> p(n, -1);
	d[0] = 0;
	for(;;){
		bool any = false;

		for (int j = 0; j < m; ++j)
			if(d[e[j].u]<MOD)
				if(d[e[j].u]+e[j].w < d[e[j].v])
				{
					d[e[j].v] = d[e[j].u]+e[j].w;
					p[e[j].v] = e[j].u;
					any = true;
				}
		if(!any)break;
	}
	//display d here
	for(auto x:d){
		cout<<x<<" ";
	}

	//Retrieving the path
	if(d[dest] == MOD)
		cout<<"No path exist to dest";
	else{
		vector<int> path;
		for(int cur = dest; cur!=-1; cur = p[cur] ){
			path.push_back(cur);
		}
		reverse(path.begin(),path.end());

		cout<<"Path from "<<0<<" to "<<dest<<" : ";
		for(size_t i=0; i <path.size();i++)
			cout<<path[i]<<" ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;

	for (int i = 0; i < m; ++i){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}

	cin>>dest;

	ford();

	return 0;
}