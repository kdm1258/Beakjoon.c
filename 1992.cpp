#include <bits/stdc++.h>
using namespace std;
int arr[66][66];
int n;
void Zip(int x, int y, int size){
	int flag = 1;
	int cmp = arr[x][y];
	for (int i = x ; i <= x+size-1 ; i++){
		for (int j = y ; j <= y+size-1 ; j++){
			if (arr[i][j] != cmp){flag = 0; break;}
		}
		if (flag == 0) break;
	}
	if (!flag){
		cout<<"(";
		Zip(x, y, size/2);
		Zip(x, y+size/2, size/2);
		Zip(x+size/2, y, size/2);
		Zip(x+size/2, y+size/2, size/2);
		cout<<")";
	}
	else{
		cout<<cmp;
	}
}
int main(void){
	cin>>n;
	for (int i = 1 ; i <= n ; i++){
		string str;
		cin>>str;
		for(int j = 1 ; j <= n ; j++){
			arr[i][j] = str[j-1]-'0';
		}
	}
	Zip(1,1,n);
}
