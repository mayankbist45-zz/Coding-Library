
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii int
#define MOD 1000000007

ll m,n;
vector<pair<ll,ll>> e[100500];
ll parent[100500];
ll dist[100500];
set<pair<ll,ll> > a;

void input(){
	cin>>m>>n;
	for (int i = 0; i < n; ++i)
	{
		ll a1,a2,a3;
		cin>>a1>>a2>>a3;
		e[a1].push_back({a2,a3});
		e[a2].push_back({a1,a3});
	}
}

void dijkstra(ll src){
	dist[src] = 0;
	parent[src] = -1;
	a.insert({0,src});
	while( !a.empty()){
		pair <ll,ll> cur = *(a.begin());
		a.erase(a.begin());
		for(auto i:e[cur.second]){
			int now = i.first , edge = i.second;
			if( dist[now] == -1){
				parent[now] = cur.second;
				dist[now] = dist[cur.second] + edge;
				a.insert({dist[now],now});
			}
			else
				if( dist[now] > dist[cur.second] + edge){
					a.erase({dist[now],now});
					parent[now] = cur.second;
					dist[now] = dist[cur.second] + edge;
					a.insert({dist[now],now});
				}

		}
	}
}


int main() {

	input();
	memset(dist,-1,sizeof dist);
	dijkstra(1);

	ll now = m;
	if(dist[now] == -1){
		cout<<"-1 is a bitch";
		return 0;
	}

	vector<ll> ans;
	while(now!=-1){
		ans.push_back(now);
		now = parent[now];
	}

	for(int x = ans.size()-1;x>=0;x--)
		cout<<ans[x]<<" ";

	return 0;
}