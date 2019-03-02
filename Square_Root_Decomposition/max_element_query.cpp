
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int query(int * blocks,int *ar,int L,int R,int rn){

	int ans = INT32_MIN;
	//Left Part
	while(L<R && L%rn!=0){
		ans = max(ans,ar[L++]);
	}

	//Middle Part
	while( L+rn <= R){
		int block_id = L/rn;
		ans = max(ans,blocks[block_id]);
		L+= rn;
	}

	//Right Part
	while(L<=R){
		ans = max(ans,ar[L++]);
	}

	return ans;
}

//Update the blocks
void update(int *blocks,int *ar,int i,int val,int rn){
	int block_id = i/rn;
	blocks[block_id] = max(blocks[block_id],val);
	ar[i] = val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	int ar[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>ar[i];
	}

	int rn = sqrt(n);
	int *blocks =  new int[rn+1];

	int block_id = -1;

	//Building the block array
	for (int i = 0; i < n; ++i)
	{
		if(i%rn==0)
			block_id++;

		blocks[block_id] = max(blocks[block_id] , ar[i]);
	}

	//query function
	int l,r;
	cin>>l>>r;

	//1 based indexing
	l--,r--;
	cout<<query(blocks,ar,l,r,rn);

	return 0;
}