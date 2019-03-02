
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int z=1;
int g[101][101] = {};
bool on[101];
void warshall(){

	double sum = 0,nans=0;
	for (int k = 0; k < 101; ++k)
		for (int i = 0; i < 101; ++i)
			for (int j = 0; j < 101; ++j)
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);

	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			if(i==j)
				continue;
			if(on[i] && on[j]){
				sum += g[i][j];
				nans++;
			}
		}
	}

	cout<<"Case "<<z++<<": average length between pages = ";
	cout<<fixed<<setprecision(3)<<(sum)/(nans)<<" clicks"<<endl;
}
int a,b;
int main() {
	
	while(true){
		int n;
		memset(g,63,sizeof g);
		memset(on,false,sizeof on);
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)
			break;
		
		while(true){
			g[a][b] = 1;
			on[a] = on[b] = true;
			scanf("%d%d",&a,&b);
			if(a==0 && b==0)
			break;
		}
		warshall();
	}
	

	return 0;
}