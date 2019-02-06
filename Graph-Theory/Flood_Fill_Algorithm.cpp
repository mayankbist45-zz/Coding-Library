
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int R=20,C=20;

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
void floodFill(int mat[][50],int i,int j,char ch,char color){
	//Base Case
	if(i<0||j<0||i>=R||j>=C)
		return;

	//Condition for filling color
	if(mat[i][j]!=ch){
		return;
	}

	//Recursive call
	mat[i][j]=color;
	for(int k=0;k<4;k++){
		floodFill(mat,i+dx[k],j+dy[k],ch,color);
	}
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}
