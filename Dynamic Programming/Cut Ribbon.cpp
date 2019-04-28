
#include <bits/stdc++.h>

int dp[5000];
int a[3];
using namespace std;
int solve(int n){
	if(n==0)
		return 0;

	if(dp[n]!=-1)
		return dp[n];

	int ans = INT_MIN;
	for(int i=0;i<3;i++){
		if(n>=a[i])
			ans = max(ans,1 + solve(n-a[i]));
	}
    return dp[n] = ans;
}

int main() {

	int n;
	cin>>n>>a[0]>>a[1]>>a[2];
	memset(dp,-1,sizeof dp);
	cout<<solve(n);

	return 0;
}