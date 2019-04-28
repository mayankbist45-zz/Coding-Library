
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool isPalin(string s){
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;


	while(t--){
		string s;
		cin>>s;

		bool flag = false;

		int n = s.size();

		s += s;
		for(int i=0;i<=s.size()-n;i++){
			if(isPalin(s.substr(i,n))){
				cout<<1<<endl;
				flag = true;
				break;
			}
		}
		if(flag)continue;

		cout<<0<<endl;

	}

	
	return 0;
}