#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[55];
int M;
int Index[55];
int box[1010101];
void sol(void){
	int j = 1;
	int cnt = 0;
	for(int j = 1 ; j <= n ; j++){
		for(int i = 1 ; i <= M ; i++){
			if(box[i] != 0 && i <= arr[j]){
				Index[j] = i;
			}
			else if(i > arr[j]) break;
		}
	}
	while(Index[n] != 0 && j>0){
		for(int i = 1 ; i <= n ; i++){
			if(box[Index[i]] != 0){ 
				box[Index[i]]--;
				j = Index[i];
			
				if(box[Index[i]] == 0){
					while(box[j] == 0 && j>0){
						j--;
					}
					Index[i] = j;
				}
			}
			else{
				j = Index[i];
				while(box[j] == 0 && j>0){
					j--;
				}
				Index[i] = j;
				box[Index[i]]--;
			
				if(box[Index[i]] == 0){
					while(box[j] == 0 && j>0){
						j--;
					}
					Index[i] = j;
				}
			}
		}
		cnt++;
	}
	cout<<cnt;
}
int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>arr[i];
	}
	cin>>m;
	for(int i = 1 ; i <= m ; i++){
		int tmp; cin>>tmp;
		box[tmp]++;
		if(M<tmp) M = tmp;
	}
	sort(arr+1,arr+n+1);
	if(M>arr[n]) {cout<<-1; return 0;}
	sol();
}
