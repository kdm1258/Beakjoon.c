#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
char arr[505][505];
map<char, int> Map[505][505];
void change(int x, int y, char a){
	for(int i = x ; i <= n ; i+=k){
		for(int j = y ; j <= m ; j+=k){
			if(arr[i][j] != a){
				arr[i][j] = a;
				cnt++;
			}	
		}
	}
}
int main(void){
	cin>>n>>m>>k;
	for(int i = 1 ; i<= n ; i++){
		string str;
		cin>>str;
		for(int j = 1 ; j <= m ; j++){
			arr[i][j] = str[j-1];
		}
	}
	for(int i = 1 ; i <= n; i++){
		for(int j =1 ; j <= m ; j++){
			if(Map[(i-1)%k+1][(j-1)%k+1].find(arr[i][j])==Map[(i-1)%k+1][(j-1)%k+1].end()){
				Map[(i-1)%k+1][(j-1)%k+1].insert(make_pair(arr[i][j],1));
			}
			else{
				Map[(i-1)%k+1][(j-1)%k+1][arr[i][j]]++;
			}
		}
	}
	for(int i = 1 ; i <= k ; i++){
		for(int j = 1 ; j <= k ; j++){
			int Max = INT_MIN;
			char c = '\0';
			for(const auto& pair : Map[i][j]){
				if(Max < pair.second){
					Max = pair.second;
					c = pair.first;
				}
				
			}
			change(i, j, c);
		}
	}
	cout<<cnt<<"\n";
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m; j++){
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
}
