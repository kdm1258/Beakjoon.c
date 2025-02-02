#include <bits/stdc++.h>
using namespace std;
deque <int> dq;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>str;
		if(!str.compare("push_front")){
			int m;
			cin>>m;
			dq.push_front(m);
		}
		else if(!str.compare("push_back")){
			int m;
			cin>>m;
			dq.push_back(m);
		}
		else if(!str.compare("pop_front")){
			if(!dq.empty()){
				cout<<dq.front()<<"\n";
				dq.pop_front();
			}
			else{
				cout<<-1<<"\n";
			}
		}
		else if(!str.compare("pop_back")){
			if(!dq.empty()){
				cout<<dq.back()<<"\n";
				dq.pop_back();
			}
			else{
				cout<<-1<<"\n";
			}
		}
		else if(!str.compare("size")){
			cout<<dq.size()<<"\n";
		}
		else if (!str.compare("empty")){
			cout<<dq.empty()<<"\n";
		}
		else if (!str.compare("front")){
			if (!dq.empty()){
				cout<<dq.front()<<"\n";
			}
			else cout<<-1<<"\n";
		}
		else if (!str.compare("back")){
			if (!dq.empty()){
				cout<<dq.back()<<"\n";
			}
			else cout<<-1<<"\n";
		}
		 
	}
}
