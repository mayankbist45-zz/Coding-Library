
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

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
	if(n == 1)
	{
		cout<<0;
		return 0;
	}
	if(n == 2)
	{
		if((abs(ar[0]-ar[1]))%2==0)
			cout<<abs(ar[0]-ar[1])/2;
		else
			cout<<-1;
		return 0;
	}
	set<int> s;
	for (int i = 1; i < n; ++i)
	{
		s.insert(abs(ar[i]-ar[i-1]));
	}
	if(*(s.begin()) == 0 && s.size() <= 2){
		cout<<*(s.rbegin());
	}
	else
		cout<<-1<<endl;
	return 0;
}