
#include <bits/stdc++.h>

using namespace std;

int ar[10000];
int bit[10000] = {};

void update(int i,int inc,int N){

	while(i<=N){
		bit[i] += inc;
		i += (i&(-i));
	}
}
//sum till ith index
int query(int i){
	int ans=0;
	while(i>0){
		ans += bit[i];
		i -= (i&(-i));
	}
	return ans;
}
int main() {

	int n;
	cin>>n;

	//Build the bit
	for (int i = 1; i <= n; ++i)
	{
		cin>>ar[i];
		update(i,ar[i],n);
	}
	
	//query
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(r)-query(l-1)<< endl;
	}

	return 0;
}