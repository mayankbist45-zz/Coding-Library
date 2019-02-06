
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,count=0;
	cin>>n;
	while(n>0){
		if(n&1){
			count++;
		}
		//Both methods will work
		// n=n/2;
		n=n>>1
	}
	cout<<count;
	return 0;
}
