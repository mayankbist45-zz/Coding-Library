
#include <bits/stdc++.h>

using namespace std;

int LCS(string x,string y){

    int a = x.size();
    int b = y.size();
    int dp[a+1][b+1] = {};
    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            if(i == 0 || j==0)
                dp[i][j] = 0;
            else if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[a][b];
}

int main() {

    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;

        string x,y;
        cin>>x>>y;

        cout<<LCS(x,y)<<endl;
    }
    return 0;
}