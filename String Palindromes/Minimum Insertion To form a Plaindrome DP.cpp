
#include <bits/stdc++.h>

using namespace std;


int solve(string s,int n){
    int table[n][n] ;

    memset(table,0,sizeof table);

    for(int g = 1;g<n;g++){
        for(int i = 0,j=g;j<n;i++,j++){
            table[i][j] = (s[i] == s[j])?(table[i+1][j-1]) : (min(table[i+1][j],table[i][j-1]) + 1);
        }
    }
    return table[0][n-1];
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
        cout<<solve(s,n)<<endl;
    }
    return 0;
}

