
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;

	int ar[n];
	for (int i = 0; i < n; ++i)
		cin>>ar[i];

	int dp[n];
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		if(i && ar[i]>=ar[i-1])
			dp[i] = 1+dp[i-1];
	}
	cout<<*max_element(dp,dp+n)<<endl;

	return 0;
}