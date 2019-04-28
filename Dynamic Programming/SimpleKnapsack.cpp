#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    int n, W;
    cin>>n>>W;

    vector<ll> dp(W+1);
    for(int items = 0 ;items < n; items++){
        int weight , value;
        cin>>weight>>value;

        for(int weight_already = W - weight; weight_already >= 0; weight_already--){
            dp[weight_already + weight] = max(dp[weight_already + weight], value + dp[weight_already]);
        }
    }
    cout<<dp[W];
}
#pragma clang diagnostic pop