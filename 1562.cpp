#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[10][101][1024];
int n;
void sol(){
    for(int i = 1 ; i <10 ; i++){
        dp[i][1][1<<i] = 1;
    }
    for(int i = 2 ; i<= n ; i++){
        for(int j = 0 ; j < 10 ; j++){
            for(int k = 0 ; k < 1024 ; k++){
                if(j==0){
                    dp[j][i][k|(1<<j)] += dp[1][i-1][k]%1000000000;
                }
                else if(j==9){
                    dp[j][i][k|(1<<j)] += dp[8][i-1][k]%1000000000;
                }
                else{
                    dp[j][i][k|(1<<j)] += dp[j-1][i-1][k]%1000000000 + dp[j+1][i-1][k]%1000000000;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0 ; i <10 ; i++){
        ans = (ans+dp[i][n][1023])%1000000000;
    }
    cout <<ans<< '\n';
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sol();
}