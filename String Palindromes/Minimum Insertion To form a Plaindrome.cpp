
#include <bits/stdc++.h>

using namespace std;


int solve(string s,int i,int j){
    if(i == j)
        return 0;
    if(i == j-1)return (s[i] == s[j])?0:1;


    if(s[i] == s[j])
       return solve(s,i+1,j-1);

    else
        return min(solve(s,i,j-1),solve(s,i+1,j)) + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n = s.size();
        cout<<solve(s,0,n-1)<<"\n";
    }


    return 0;
}

