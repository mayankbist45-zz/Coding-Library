
#include <bits/stdc++.h>

using namespace std;


int n,m,wt=0;
vector<int> parent(100);
vector<int> rnk(100,0);
vector< pair<int ,int >> res;

int find_set(int a){
	if(a==parent[a])
		return a;

	return parent[a] = find_set(parent[a]);
}

void union_sets(int a,int b){
	a = find_set(a);
	b = find_set(b);

	if(a!=b){
		if(rnk[a] < rnk[b])
			swap(a,b);

		parent[b] = a;

		if(rnk[a]==rnk[b])
			rnk[a]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	vector < pair<int , pair<int,int> > > g;//(weight,u,v)

	for (int i = 0; i < m; ++i)
	{
		int u,v,w;
		cin>>u>>v>>w;

		//0 based indexing
		g.push_back({w,{u,v}});
	}

	sort(g.begin(),g.end());

	//Initialize parent array
	//Make set function
	for (int i = 0; i < n; ++i)
		parent[i] = i;


	//Moving over the sorted edges for MST
	int x = 1;
	for (int i = 0; i < m; ++i)
	{
		if(x==n)break;
		int a = g[i].second.first;
		int b = g[i].second.second;

		int w = g[i].first;

		if(find_set(a)!=find_set(b)){
			wt += w;
			x++;
			res.push_back({a,b});
			union_sets(a,b);
		}
	}

	//Printing the net weight of MSt
	cout<<wt<<endl;

	//Printing the edges of MST
	for (int j = 0; j < n-1; ++j) {
		cout<<res[j].first<<" "<<res[j].second<<endl;
	}

	return 0;
}