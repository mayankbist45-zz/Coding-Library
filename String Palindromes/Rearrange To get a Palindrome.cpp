
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		map<char,int> mp;
		for(auto x:s)mp[x]++;

		int odd = 0;
		for(auto x:mp){
			if(x.second&1)odd++;
		}
		if(odd <=  1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}