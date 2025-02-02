#include <bits/stdc++.h>
using namespace std;
int n;
char expr[2020], con;
void calc(void){
	int pre = (expr[0] == 'T' ? 1 : 0);
	int next = 0;
	for (int i = 2 ; i < n-2 ; i+=2){
		next = expr[i] == 'T' ? 1 : 0;
		if(expr[i-1] == '&'){
			pre = pre && next;
		}
		else pre = pre || next;
	}	
	next = expr[n-1];
	if(expr[n-2] == '|'){	
		if (pre==1 && next == 'T'){
			cout<<(con == 'T' ? 0 : 2);
		}
		else if(pre == 0 && next == 'F'){
			cout<<(con == 'T' ? 1 : 0);
		}
		else{
			cout<< (con == 'T' ? 0 : 1);
		}
	}
	else{
		if (pre==1 && next == 'T'){
			cout<<(con == 'T' ? 0 : 1);
		}
		else if(pre == 0 && next == 'F'){
			cout<<(con == 'T' ? 2 : 0);
		}
		else{
			cout<< (con == 'T' ? 1 : 0);
		}
	}
}
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>expr[i];
	}
	cin>>con;
	if(n==1){
		cout<<(expr[0] != con ? 1 : 0);
	}
	else calc();	
}

