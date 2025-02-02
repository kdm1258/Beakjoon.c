#include <bits/stdc++.h>
using namespace std;
char str[22];
int n, upper, lower;
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		bool hyphen = false;
		upper = 0; lower = 0;
		cin>>str;
		if(strlen(str) > 10) continue;
		for(int j = 0 ; j < strlen(str) ; j++){
			if(str[j] >= 97 && str[j] <= 122) lower++;
			else if(str[j] >= 65 && str[j] <= 90) upper++;
			else if(str[j] == 45) hyphen = true;
			else continue;
		}
		if((lower != 0 || upper != 0 || hyphen) && lower >= upper) 
		{
			cout<<str; 
			break;
		}
	}
}
