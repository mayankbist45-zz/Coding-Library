
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int editDistance(string x,string y){
	int a = x.size();
	int b = y.size();

	int dp[a+1][b+1];
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int a,b;
		cin>>a>>b;

		string x,y;
		cin>>x>>y;

		cout<<editDistance(x,y)<<endl;
	}

	return 0;
}