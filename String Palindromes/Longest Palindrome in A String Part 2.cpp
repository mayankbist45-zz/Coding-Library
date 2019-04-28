/*
 * dp is a nothing but a game of tables
 * In order to search for the longest palindrome that ever walked the earth in a string
 * we can always create a table to store true or false
 *
 *
 * This implementation gives a horrendous and first approach
 *
 */
#include <bits/stdc++.h>

using namespace std;


void solve(string s){

    int n = s.size();
    int dp[n][n];

    memset(dp,0,sizeof dp);

    for(int i = 0;i<n;i++){
        dp[i][i] = 1;
    }

    for(int gap = 1;gap < n;gap++){
        for(int i = 0,j = gap;j<n;i++,j++){
            if((s[i] == s[j]) && (i+1 == j))
                dp[i][j] = 2;

            else if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];

            else  dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }

    int res = -1,x;

    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i<=j){
                if(dp[i][j] == 1 && j-i > res){
                    res = j-i;
                    x = i;
                }
            }
        }
    }
    cout<<s.substr(x,res+1)<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;


    while(t--){
        string s;
        cin>>s;

        solve(s);
    }

    return 0;
}