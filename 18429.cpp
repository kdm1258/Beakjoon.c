#include <bits/stdc++.h>
using namespace std;
int n,k;
int sum, cnt, node;
int c[8];
int exercise[8];
void sol(int s){
    c[s]=1;
    node++;
    sum += exercise[s];
    if(sum<0){c[s]=0; node--; sum -= exercise[s]; return;}
    if(node==n){
        cnt++;
    }
    else{
        for(int i = 0 ; i < n ; i++){
            if(c[i]==0){
                sol(i);
            }
        }
    }
    c[s]=0; node--; sum -= exercise[s];
}
int main(void){
    cin>>n>>k;
    for (int i = 0 ; i < n ; i++){
        cin>>exercise[i];
        exercise[i]-=k;
    }
    for(int i = 0 ; i < n ; i++){
        sol(i);
    }
    cout<<cnt;
}