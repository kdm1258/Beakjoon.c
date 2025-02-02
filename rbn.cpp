#include <bits/stdc++.h>
using namespace std;
int A[1010101], B[1010101];
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;

	for(int i = 0 ; i < n ; i++) cin>>A[i];
	stack <int> stk;
	for(int i = n-1 ; i >=0 ; i--){
		while(!stk.empty() && stk.top() <= A[i]) stk.pop();
		if(stk.empty())	B[i] = -1;	
		else B[i] = stk.top();	
		stk.push(A[i]);
	}
	for(int i = 0 ; i < n ; i++) cout<<B[i]<<" ";
}
