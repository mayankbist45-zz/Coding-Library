//Segmented Sieve is used to calculate a range of prime numbers
//|b-a|<=10^6
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007


const int N = 1000000;
int p[N]={};
void Sieve(ll n){
	p[0]=p[1]=0;
	p[2]=1;
	for (int i = 3; i <= n; i+=2)
	{
		p[i] = 1;
	}
	for(int i=3;i<=n;i++){
		if(p[i]){
			for(int j=i*i; j<=n; j+=2*i){
				p[j] = 0;
			}
		}
	}
}

int segmented_sieve(ll a,ll b){
	Sieve((ll)sqrt(b));
	bool pp[b-a+1];	
	memset(pp,1,sizeof(pp));
	for(ll i=2;i*i<=b;i++){
		for(ll j=a;j<=b;j++){
			if(p[i]){
				if(j==i)
					continue;
				if(j%i == 0)
					pp[j-a] = 0;
			}
		}
	}
	for(ll i=a;i<=b;i++){
		if(pp[i-a])
			cout<<i<<" ";
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	segmented_sieve(100,200);
	return 0;
}