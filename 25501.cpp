#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int recursion(const char *s, int l, int r){
	cnt+=1;
	if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
	int n = 0;
	cin>>n;
	for (int i = 0 ; i < n ; i++){
		char str[1010];
		cin>>str;
		cout<<isPalindrome(str)<<" "<<cnt<<"\n";
		cnt = 0;
	}
}
