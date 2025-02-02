#include <bits/stdc++.h>
using namespace std;
int n, m, x1, Y1, x2, y2;
int arr[1100][1100];
int S[1100][1100];
int sol(int x1, int y1, int x2, int y2){
	int sum = 0;
	for(int i = x1 ; i <= x2 ; i++){
		sum += S[i][y2]-S[i][y1-1];
	}
	return sum;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin>>arr[i][j];
			S[i][j] = S[i][j-1] + arr[i][j];
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cin>>x1>>Y1>>x2>>y2;
		cout<<sol(x1,Y1,x2,y2)<<"\n";
	}
}
