
#include <bits/stdc++.h>

using namespace std;

int x,y,GCD;
void extendedEuclid(int a,int b){
	//Base Case
	if(b==0){
		x=1;
		y=0;
		GCD = a;
		return;
	}

	//Recursive Case
	extendedEuclid(b,a%b);
	int cX = y;
	int cY = x - (a/b)*y;

	x = cX;
	y = cY;
}

int main() {
  
	extendedEuclid(18,30);
	cout<<x<<" "<<y;
	return 0;
}