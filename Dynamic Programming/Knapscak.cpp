
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int solve(int n,int W,int wt[],int val[]){

	if(n == 0 || W == 0){
		return 0;
	}
	if(W<wt[n-1])
		return solve(n-1,W,wt,val);

	return max(val[n-1] + solve(n-1,W-wt[n-1],wt,val),solve(n-1,W,wt,val));
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
