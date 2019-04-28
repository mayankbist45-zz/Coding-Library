
#include <bits/stdc++.h>

using namespace std;
#define maxn 100100+5

int cnt[maxn];
int dp[maxn];

int main() {
	int n,tp;
	cin>>n;

	for (int i = 0; i < n; ++i){
		cin>>tp;
		cnt[tp]++;
	}

	dp[0] = 0;
	for(int i=1;i<maxn;i++){
		if(cnt[i])
			dp[i] = dp[i-2] + cnt[i]*i;
		dp[i] = max(dp[i],dp[i-1]);
	}

	cout<<dp[(int)maxn-1]<<endl;
	return 0;
}