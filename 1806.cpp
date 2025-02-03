#include <bits/stdc++.h>
using namespace std;   
using ll = long long;
int n;
int s;
ll arr[101010];
int sol(){
    int res=INT_MAX;
    int i = 1, j = 0;
    while(i <= n){
        if(arr[i] - arr[j] >= s){
            if(res > i-j){
                res = i-j;
            } 
            j++;
        }
        else{
            i++;
        }
    }
    if(i==n+1 && j==0) return 0;    //i == n+1 && j == 0 이면 s보다 큰 수가 없는 경우
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    cout<<sol();
    
}
