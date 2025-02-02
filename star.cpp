#include <bits/stdc++.h>
using namespace std;
int starr[3073][3073];
void fillStar(int i, int j){
	starr[i][j] = 1;
	starr[i+1][j-1] = 1;
	starr[i+1][j+1] = 1;
	for (int k = j-2; k<=j+2 ; k++) starr[i+2][k] = 1;
}
void star(int i ,int j, int n){
	if (n==3){
		fillStar(i,j);	
		return;
	}
	else {
		star(i,j,n/2);
		star(i+n/2, j-n/2,n/2);
		star(i+n/2, j+n/2,n/2);
	}
}
int main(void){
	int n;
	cin>>n;
	int i = 0;
	int j = n;
	star(i,j,n);
	for(int i = 0 ; i < n ; i++){
		for(int j = 1 ; j <= 2*n ; j++){
		if(starr[i][j] == 1) cout<<"*";
		else cout<<' ';
		}
	cout<<"\n";
	}
}
