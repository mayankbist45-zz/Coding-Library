#include <bits/stdc++.h>
using namespace std;

double ar[3000];
int n;
double ans = 0;
double solve(int i,int heads,double val){
    if(i == n){
        if(heads > (n/2)){
            ans += val;
        }
        return ans;
    }
    solve(i+1,heads+1,val * ar[i]);
    solve(i+1,heads,val*(1-ar[i]));
    return;
}

int main(){

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>ar[i];

    solve(0,0,1);

    cout<<setprecision(10)<<fixed<<ans<<endl;

    return 0;
}