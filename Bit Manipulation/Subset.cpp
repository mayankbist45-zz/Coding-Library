
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

//Generate all the bits
vector<string> v;
void filterChar(char *a,int no){
	string ans;
	int i=0;
	while(no>0){
		if(no&1)ans+=a[i];
		i++;
		no = no>>1;
	}
	v.push_back(ans);
}
void generateSubsets(char *a){
	//Generate a range of numbers from 0 to 2^n-1
	int n =strlen(a);

	int range = 1<<n-1;
	for(int i=1;i<=range;i++){
		filterChar(a,i);
	}
}  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char a[100];
	cin>>a;

	generateSubsets(a);
	for(auto x:v){
		cout<<x<<" ";
	}

	return 0;
}