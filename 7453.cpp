#include <bits/stdc++.h>
using namespace std;
int n;
int result;
int A[4000], B[4000], C[4000], D[4000];
map<int, int> AB;
map<int, int> CD;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 0 ; i <n ; i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for(int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j <n ; j++){
            AB[A[i]+B[j]]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(AB.find(-(C[i]+D[j])) != AB.end()){
                result += AB[-(C[i]+D[j])];
            }
        }
    }
    cout << result << '\n';
}