
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int n,int W,int wt[],int val[]){

	int dp[n+1][W+1] = {};
	for(int i=0;i<=n;i++){
		for(int j=0;j<= W;j++){

			if(i == 0 || j==0)
				dp[i][j] = 0;
			if(j < wt[i-1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]); 
		}
	}

	return dp[n][W];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
    cin>>t;
    while(t--){

    	int n;
    	cin>>n;

    	int W;
    	cin>>W;

    	int wt[20],val[20];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>val[i];
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>wt[i];
    	}
    	
    	cout<<solve(n,W,wt,val);
    } 

	return 0;
}