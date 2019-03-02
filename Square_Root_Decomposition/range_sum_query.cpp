
#include <bits/stdc++.h>

using namespace std;

//Square Root Decomposition
//Range Sum
//Query over the array

int query(int *blocks,int *arr,int L,int R,int rn){
	int sum = 0;

	//Left Part
	while(L<R && L!=0 && L%rn!=0){
		sum +=arr[L++];
	}

	//Middle Part
	while(L  + rn <= R){
		int block_id = (L/rn);
		sum += blocks[block_id];
		L += rn;
	}

	//Right Part
	while(L<=R){
		sum+=arr[L++];
	}

	return sum;
}

//Update Part
void update(int *blocks,int * arr,int i,int val,int rn){

	int block_id = i/rn;
	blocks[block_id] += (val-arr[i]);
	arr[i] = val;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a[] = {1,3,5,2,7,6,3,1,4,8};
	int n = sizeof(a)/sizeof(int);

	//root of size
	int rn = sqrt(n);
	int *blocks = new int[rn+1];

	int block_id = -1;

	//Build a block array
	for (int i = 0; i < n; ++i)
	{
		if(i%rn==0){
			block_id++;
		}
		blocks[block_id] += a[i];
	}
	//Print the array
	// for (int i = 0; i <= rn; ++i)
	// {
	// 	cout<<blocks[i]<<endl;
	// }

	int l,r;
	cin>>l>>r;
	update(blocks,a,2,15,rn);
	cout<<query(blocks,a,l,r,rn);
	return 0;
}