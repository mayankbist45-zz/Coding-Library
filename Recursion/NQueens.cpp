
#include <bits/stdc++.h>

using namespace std;
bool solveNQueen(int board[10][10],int i,int n,int &ans){
	if(i==n){
		//Success
		//Print the board
	}

	//Recursive Case
	for(int j=0;j<n;j++){
		if(isSafe(board,i,j,n)){
			//Place the queen
			board[i][j] = 1;
			bool nextQueenPossible = solveNQueen(board,i+1,n,ans);
			if(nextQueenPossible)
				return true;
		}
	}
	//Backtrack Here
	board[i][j]=0;
	return false;
}

int main() {
	
	int n;
    cin>>n;	
    int board[10][10]={0};
    int ans=0;
    solveNQueen(board,0,n,&ans);
    cout<<ans;
	return 0;
}