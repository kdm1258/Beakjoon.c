#include <bits/stdc++.h>
using namespace std;
int n;
int arr[101][101];
void row(){
	int S=0;
	int cnt=0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(arr[i][j] == 1) S++;
			else{
				if(S>=2) cnt++;
				S=0;	
			}	
		}
		if(S>=2) cnt++;
		S=0;
	}
	cout<<cnt<<"\n";
}
void col(){
	int S=0;
	int cnt=0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(arr[j][i] == 1) S++;
			else{
				if(S>=2) cnt++;
				S=0;	
			}	
		}
		if(S>=2) cnt++;
		S=0;
	}
	cout<<cnt<<"\n";
}

int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			char tmp; cin>>tmp;
			arr[i][j] = tmp =='.' ? 1 : 0;
		}
	}
	row();
	col();
}
