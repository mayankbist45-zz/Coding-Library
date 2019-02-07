
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
const int N = 1000000;
int p[N]={};
void Sieve(int n){
	p[0]=p[1]=0;
	p[2]=1;

	//Let us mark all odd no are primes
	for (int i = 3; i <= n; i+=2)
	{
		p[i] = 1;
	}

	//Optimisation
	//1.Iterate only over odd no
	for(int i=3;i<=n;i++){
		if(p[i]){
			//Mark all the multiples of that no as not prime
			//2.Start the loop from i^2
			//j+=2*i that means we are iterating over odd no's only
			for(int j=i*i; j<=n; j+=2*i){
				p[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	Sieve(n);

	for(int i=0;i<=n;i++){
		if(p[i])
			cout<<i<<" ";
	}
	return 0;
}