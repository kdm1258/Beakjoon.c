#include <bits/stdc++.h>
using namespace std;
int n, depth;
int arr[1010];
int C[1010];
vector<int> G[1010];
void DFS(int s,int p){
    arr[s] = ++depth;
    C[p] = 1;
    for(auto a: G[p]){
        if(C[a] == 0){
            DFS(s,a);
            C[a] = 0;
            --depth;
        }
    }
    C[p] = 0;
}
int main(void){
    cin>>n;
    int max = 0;
    int res = 0;
    for(int i = 1 ; i <= n ; i++){
        int tmp; cin>>tmp;
        G[i].push_back(tmp);
    }
    for(int i = 1 ; i <= n ; i++){
        depth = -1;
        DFS(i,i);
    }
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] > max){
            max = arr[i];
            res = i;
        }
    }
    cout<<res<<'\n';
    return 0;
}