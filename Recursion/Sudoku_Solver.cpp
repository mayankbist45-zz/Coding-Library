
#include <bits/stdc++.h>

using namespace std;

bool canPlace(int mat[9][9],int i,int j,int n,int number){
	//Validting for rows and columns
	for(int x=0;x<n;x++){
		if(mat[x][j]==number||mat[i][x]==number)
			return false;
	}

	//Checking whether the value is valid for the box 
	//or not
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int a=sx;a<sx+rn;a++){
		for(int b=sy;b<sy+rn;b++){
			if(mat[a][b]==number)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int mat[9][9],int i,int j,int n){
	if(i==n)
	{
		//print Sudoku
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<mat[x][y]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	//Case for row ending
	if(j==n)
		return solveSudoku(mat,i+1,0,n);

	//Skipping the already filled cell
	if(mat[i][j]!=0)
		return solveSudoku(mat,i,j+1,n);

	//Recursive part
	//Filling the number with possible values
	for(int number=0;number<=n;number++){
		if(canPlace(mat,i,j,n,number)){
			mat[i][j] = number;
			bool couldWeSolve = solveSudoku(mat,i,j+1,n);
			if(couldWeSolve)
				return true;
		}
	}

	//Backtracking Occurs Here
	mat[i][j] = 0;
	return false;
}
int main() {
	
	int mat[9][9]=
      {
          {4,0,0,0,0,0,1,0,0},
          {0,0,0,0,0,6,3,8,0},
          {0,0,0,5,0,0,2,6,0},
          {3,0,0,0,0,9,7,0,6},
          {0,0,0,1,6,3,0,0,0},
          {8,0,9,7,0,0,0,0,3},
          {0,3,4,0,0,7,0,0,0},
          {0,1,2,3,0,0,0,0,0},
          {0,0,8,0,0,0,0,0,7}
      };
      solveSudoku(mat,0,0,9);
	return 0;
}