#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

#define max 200
int parent[max],r[max];

void make_set(int v){
    parent[v] = v;
    r[v] = 0;
}

int find_set(int v){
    if(v==parent[v])
        return v;

    //Applying Compression
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b)
    {
        if(r[a] < r[b])
            swap(a,b);
        parent[b] = a;

        //To increse the rank on the basis of 
        //parent child relation
        if(r[a] == r[b])
            r[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    return 0;
}