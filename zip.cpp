#include <bits/stdc++.h>
using namespace std;
//vector<vector<char>> arr;
int arr[64][64] = {0};
void zip(int x, int y, int lenth){
	int same = arr[x][y];
	bool flag = 1;
	for (int i = x  ; i < x+ lenth ; i++){
		for ( int j = y ; j < y+ lenth ; j++){
			if (same != arr[i][j]){
				flag = 0;
				break;
			}
		}	
		if (!flag) break;
	}
	if (flag) cout<<same;
	else{
	cout<<'(';
	zip(x, y, lenth/2);
	zip(x, y + lenth/2, lenth/2);
	zip(x + lenth/2, y, lenth/2);
	zip(x + lenth/2 , y + lenth/2 , lenth/2);
	cout<<')';
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	string str;
	cin>>n;
	for (int i = 0 ; i < n ; i++){
		cin>>str;
		for (int j = 0 ; j < n ; j++){
			arr[i][j] = str[j] - '0';
		}
	}
	zip(0,0,n);
}
