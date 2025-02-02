#include <bits/stdc++.h>
using namespace std;
int main(void){
	stack<int> stk;
	int n;
	cin>>n;

	for (int i = 0 ; i < n ; i++){
		string str;
		int tmp = 0;
		cin>>str;
			if(!str.compare("push")){
				cin>>tmp;
				stk.push(tmp);
			}
			else if(!str.compare("pop")){
				if(stk.empty()) cout<<-1;
				else{
				cout<<stk.top();
				stk.pop();
				}
				cout<<"\n";
			}
			else if(!str.compare("size")){
				cout<<stk.size();
				cout<<"\n";
			}
			else if(!str.compare("empty")){
				cout<<stk.empty();
				cout<<"\n";
			}
			else if(!str.compare("top")){
				if(stk.empty()){
					cout<<-1;
				}
				else{
				cout<<stk.top();
				}
				cout<<"\n";
			}
		}
	return 0;	
}
