#include<bits/stdc++.h>

using namespace std;

//Knuth Morris Pratt Algorithm
void kmp(string a,string b){
    int na = a.length();
    int nb = b.length();
    int ar[nb];

    ar[0] = 0;
    for(int i=1,j= 0;i<nb;){
        if(b[i] != b[j] && j==0){
            ar[i++] = 0;
        }
        else if(b[i] != b[j] && j!=0){
            j = ar[j-1];
        }
        else{
            ar[i++] = j+1;
            j++;
        }
    }

    int i = 0;
    int j = 0;
    int idx = j;
    while(i < na ){
        
        if(a[i] == b[j]){
            i++;j++;
        } else{
            if(j != 0){
                idx = j;
                j = ar[j-1];
            }
            else
                i++;
        }
        if(j == nb){
            cout<< "FOUND at " << i-j+1 <<endl;
            j = ar[j-1];
        }
    }
}

int main(){

    string a,b;
    cin>>a>>b;

    kmp(a,b);
}