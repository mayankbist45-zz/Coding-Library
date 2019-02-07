
#include <bits/stdc++.h>

using namespace std;

void subSequences(char *in,char* out,int i,int j){
	//Base Case
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<",";
		return;
	}

	//Recurcive Case
	//Include the current char
	out[j] = in[i];
	subSequences(in,out,i+1,j+1);
	//Exclude the current char
	subSequences(in,out,i+1,j);
}


int main() {
	char input[100],output[100];
	cin>>input;
	subSequences(input,output,0,0);
	return 0;
}